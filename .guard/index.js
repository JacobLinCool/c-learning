const fs = require("fs");
const path = require("path");
const maker = require("./maker");
const checker = require("./checker");

const skipMake = process.argv.includes("--skip-make");
const skipCheck = process.argv.includes("--skip-check");

(async () => {
    const homeworks = getHomeworks();

    if (!skipMake) {
        for (const homework of homeworks) {
            try {
                await maker(homework);
            } catch (err) {
                console.error(err);
            }
        }
    }

    if (!skipCheck) {
        for (const homework of homeworks) {
            try {
                await checker(homework);
            } catch (err) {
                console.error(err);
            }
        }
    }
})();

function getHomeworks() {
    const folders = fs.readdirSync(path.join(__dirname, "../"));
    return folders.filter((folder) => fs.lstatSync(path.join(__dirname, "../", folder)).isDirectory() && folder.match(/^hw[0-9]+$/));
}
