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
            findFilesByRegex(path.join(__dirname, "../", homework), /hw\d{4}\.c$/)
                .filter(
                    (file) =>
                        findFilesByRegex(path.join(__dirname, "../", homework), new RegExp("^" + path.basename(file).replace(".c", "") + "$")).length !== 1
                )
                .forEach((file) => {
                    log(`Cannot find compiled file [${path.basename(file).replace(".c", "")}] for [${path.basename(file)}]`);
                });
        } catch (error) {
            process.exit(1);
        }
    }
}

function log(...msg) {
    console.log("[Checker]", ...msg);
}

module.exports = check;
