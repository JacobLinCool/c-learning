const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);

async function check(homework) {
    try {
        console.log("=====");
        console.log(`Running "make" for ${homework}`);
        const { stdout, stderr } = await exec(`cd ${path.join(__dirname, "../", homework)} && make`);
        console.log(`STDOUT: \n${stdout}`);
        console.log(`STDERR: \n${stderr || "No Error. Excellent!"}`);
        if (stdout.match(/warning/i)) console.log("WRANING!!");
        if (stdout.match(/error/i)) console.log("ERROR!!!");
    } catch (error) {
        process.exit(1);
    }
}

module.exports = check;
