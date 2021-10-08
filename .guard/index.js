const fs = require("fs");
const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);

(async () => {
    const homeworks = getFolders();
    const failed = [],
        warning = [];
    for (const homework of homeworks) {
        try {
            console.log("=====");
            console.log(`Running "make" for ${homework}`);
            const { stdout, stderr } = await exec(`cd ${path.join(__dirname, "../", homework)} && make`);
            console.log(`STDOUT: \n${stdout}`);
            console.log(`STDERR: \n${stderr || "No Error. Excellent!"}`);
            if (stdout.match(/warning/i)) warning.push(homework);
            if (stdout.match(/error/i)) failed.push(homework);
        } catch (error) {
            console.error(error);
            failed.push(homework);
        }
    }
    console.log("=====");
    if (failed.length || warning.length) {
        console.log(`${failed.length} Failed! \n${failed.join("\n")}`);
        console.log("-----");
        console.log(`${warning.length} Warnings! \n${warning.join("\n")}`);
        process.exit(1);
    } else {
        console.log("All Checks Passed! Well Done!");
        process.exit(0);
    }
})();

function getFolders() {
    const folders = fs.readdirSync(path.join(__dirname, "../"));
    return folders.filter((folder) => fs.lstatSync(path.join(__dirname, "../", folder)).isDirectory() && folder.match(/^hw[0-9]+$/));
}
