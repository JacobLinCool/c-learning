const fs = require("fs");
const path = require("path");

function findFilesByRegex(dir, regex) {
    const files = [];
    const walk = (dir) => {
        fs.readdirSync(dir).forEach((file) => {
            const filePath = path.join(dir, file);
            const stat = fs.statSync(filePath);
            if (stat.isDirectory()) walk(filePath);
            else if (regex.test(filePath)) files.push(filePath);
        });
    };
    walk(dir);
    return files;
}

exports.findFilesByRegex = findFilesByRegex;
