const fs = require("fs");
const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);

(async () => {
    const homeworks = getFolders();
    for (const homework of homeworks) {
        try {
            console.log(`=====\n`);
            console.log(`Running "make" for ${homework}`);
            const { stdout, stderr } = await exec(`cd ${path.join(__dirname, "../", homework)} && make`);
            console.log("STDOUT:\n", stdout);
            console.log("STDERR:\n", stderr);
        } catch (error) {
            console.error(error);
        }
    }
})();

function getFolders() {
    const folders = fs.readdirSync(path.join(__dirname, "../"));
    return folders.filter((folder) => fs.lstatSync(path.join(__dirname, "../", folder)).isDirectory() && folder.match(/^hw[0-9]+$/));
}
