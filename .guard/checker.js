const { existsSync, readFileSync } = require("fs");
const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);
const { findFilesByRegex } = require("./utils");

async function check(homework) {
    if (process.platform === "win32") {
        log("Windows does not support make command.");
    } else {
        try {
            log("=====");
            log(`Running "make" for ${homework}`);
            const { stdout, stderr } = await exec(`cd ${path.join(__dirname, "../", homework)} && make`);
            log(`STDOUT: \n${stdout}`);
            if (stderr) log(`STDERR: \n${stderr}`);
            if (stdout.match(/warning/i)) console.log("WRANING!!");
            if (stdout.match(/error/i)) console.log("ERROR!!!");

            const exes = findFilesByRegex(path.join(__dirname, "../", homework), /hw\d{4}$/);
            for (const exe of exes) {
                log(`Running ${exe}`);
                const inputPath = path.dirname(exe) + "/test/" + path.basename(exe) + ".in";
                const outputPath = path.dirname(exe) + "/test/" + path.basename(exe) + ".out";
                if (!existsSync(inputPath)) {
                    log("\033[1;93m" + `[NO TEST] ${exe} does not have test file.` + "\033[0m");
                    continue;
                }
                const input = readFileSync(inputPath, "utf8");
                const output = readFileSync(outputPath, "utf8");
                await run(exe, input, output);
            }
        } catch (error) {
            process.exit(1);
        }
    }
}

async function run(exe, input = "", output = "") {
    try {
        const inputs = input.split("[[===]]");
        const outputs = output.split("[[===]]");
        for (let i = 0; i < inputs.length; i++) {
            const { stdout, stderr } = await exec(`${exe} <<< "${inputs[i]}"`, { shell: "/bin/bash" });
            if (
                stdout
                    .split("\n")
                    .map((line) => line.trim())
                    .filter((line) => line.length > 0)
                    .join("\n") !==
                outputs[i]
                    .split("\n")
                    .map((line) => line.trim())
                    .filter((line) => line.length > 0)
                    .join("\n")
            ) {
                throw new Error(`Output is not correct: ${inputs[i].replace(/\n/g, " ")}`);
            }
            if (stderr) throw new Error(stderr);
            log("\033[1;92m" + `PASSED: [${exe}] ${inputs[i].replace(/\n/g, " ")}` + "\033[0m");
        }
    } catch (error) {
        log("\033[1;91m" + `ERROR: [${exe}]` + "\033[0m", error);
    }
}

function log(...msg) {
    console.log("[Checker]", ...msg);
}

module.exports = check;
