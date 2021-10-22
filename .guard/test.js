const { existsSync, readFileSync } = require("fs");
const util = require("util");
const exec = util.promisify(require("child_process").exec);

const exe = process.argv[2],
    input = process.argv[3],
    output = process.argv[4];
if (process.argv.length !== 5 || !existsSync(exe) || !existsSync(input) || !existsSync(output)) {
    log("Usage: node test.js <exe> <input> <output>");
    process.exit(1);
} else {
    const inputData = readFileSync(input, "utf8");
    const outputData = readFileSync(output, "utf8");
    run(exe, inputData, outputData);
}

async function run(exe, input = "", output = "") {
    try {
        const inputs = input.split("[[===]]").map((x) => x.replace(/\n/g, " ").trim());
        const outputs = output.split("[[===]]");
        for (let i = 0; i < inputs.length; i++) {
            let PST = Date.now();
            let stdout, stderr;
            try {
                const result = await exec(`${exe} <<< "${inputs[i]}"`, { shell: "/bin/bash" });
                stdout = result.stdout;
                stderr = result.stderr;
            } catch (err) {
                stdout = err.stdout.toString();
                stderr = err.stderr.toString();
            }
            let PFT = Date.now();
            log("Output:", stdout || "No STDOUT");
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
                throw new Error(`Output is not correct: ${inputs[i]}`);
            }
            if (stderr) throw new Error(stderr);
            log("\033[1;92m" + `PASSED (${PFT - PST}ms): [${exe}] ${inputs[i]}` + "\033[0m");
        }
    } catch (error) {
        log("\033[1;91m" + `ERROR: [${exe}]` + "\033[0m");
        log(error.message);
    }
}

function log(...msg) {
    console.log("[Tester]", ...msg);
}
