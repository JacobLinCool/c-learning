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
        // check if every c file has a corresponding binary file
        const cFiles = await exec(`find ${path.join(__dirname, "../", homework)} -name "*.c"`);
        const cFilesList = cFiles.stdout.split("\n");
        const binaries = await exec(`find ${path.join(__dirname, "../", homework)} -name "*.out"`);
        const binariesList = binaries.stdout.split("\n");
        for (let i = 0; i < cFilesList.length; i++) {
            if (!cFilesList[i].match(/\.c$/)) continue;
            const binary = cFilesList[i].replace(/\.c$/, "");
            if (!binariesList.includes(binary)) log(`${cFilesList[i]} has no corresponding binary file`);
        }
    } catch (error) {
        process.exit(1);
    }
}

function log(...msg) {
    console.log("[Checker]", ...msg);
}

module.exports = check;
