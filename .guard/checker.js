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

            // const exes = findFilesByRegex(path.join(__dirname, "../", homework), /hw\d{4}$/);
            // for (const exe of exes) {
            //     log(`Running ${exe}`);
            //     if (!existsSync(exe + ".test")) {
            //         log(`${exe} does not have test file.`);
            //         continue;
            //     }
            //     const test = readFileSync(exe + ".test", "utf8");
            //     const [input, output] = test.split("=====").map((part) => part.trim());
            //     await run(exe, input, output);
            // }
        } catch (error) {
            process.exit(1);
        }
    }
}

async function run(exe, input = "", output = "") {
    try {
        const { stdout, stderr } = await exec(`${exe} ${input}`);
        if (
            stdout
                .split("\n")
                .map((line) => line.trim())
                .join("\n") !==
            output
                .split("\n")
                .map((line) => line.trim())
                .join("\n")
        ) {
            throw new Error("Output is not correct");
        }
        if (stderr) throw new Error(stderr);
        log(`PASSED: [${exe}]`);
    } catch (error) {
        log(`ERROR: [${exe}] `, error);
    }
}

function log(...msg) {
    console.log("[Checker]", ...msg);
}

module.exports = check;
