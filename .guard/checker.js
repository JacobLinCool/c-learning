const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);

async function check(homework) {
    try {
        log("=====");
        log(`Running "make" for ${homework}`);
        const { stdout, stderr } = await exec(`cd ${path.join(__dirname, "../", homework)} && make`);
        log(`STDOUT: \n${stdout}`);
        if (stderr) log(`STDERR: \n${stderr}`);
        if (stdout.match(/warning/i)) console.log("WRANING!!");
        if (stdout.match(/error/i)) console.log("ERROR!!!");
    } catch (error) {
        process.exit(1);
    }
}

function log(...msg) {
    console.log("[Checker]", ...msg);
}

module.exports = check;
