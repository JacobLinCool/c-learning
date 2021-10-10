const fs = require("fs");
const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);

async function make(homework) {
    const cFiles = fs.readdirSync(path.join(__dirname, "../", homework)).filter((f) => f.endsWith(".c"));
    const pdfFiles = fs.readdirSync(path.join(__dirname, "../", homework)).filter((f) => f.endsWith(".pdf"));

    const makefile = createMakefile(cFiles);
    fs.writeFileSync(path.join(__dirname, "../", homework, "Makefile"), makefile);

    // if README not exist, create it
    if (!fs.existsSync(path.join(__dirname, "../", homework, "README"))) {
        fs.writeFileSync(path.join(__dirname, "../", homework, "README"), createREADME(cFiles));
    }

    const { stdout, stderr } = await exec(`cd ${homework} && zip ${homework}.zip README Makefile ${cFiles.join(" ")} ${pdfFiles.join(" ")}`);
    console.log(stdout);
    console.error(stderr);
    if (fs.existsSync(path.join(__dirname, "../", homework, `${homework}.zip`))) {
        if (!fs.existsSync(path.join(__dirname, "../", "dist"))) fs.mkdirSync(path.join(__dirname, "../", "dist"));
        fs.renameSync(path.join(__dirname, "../", homework, `${homework}.zip`), path.join(__dirname, "../", "dist", `${homework}.zip`));
    }
}

function createMakefile(cFiles) {
    let makefile = "";
    makefile += "all: \n";
    makefile += cFiles.map((f) => `\tgcc ${f} -o ${f.split(".")[0]}`).join("\n");
    makefile += "\n";
    makefile += "clean: \n";
    makefile += cFiles.map((f) => `\trm ${f.split(".")[0]}`).join("\n");
    makefile += "\n";
    return makefile;
}

function createREADME(cFiles) {
    let readme =
        `---
    Title:  程式設計一 Homework 1
    Author: 師大資工 114 林振可 (41047029S)
    ---
    
    建議使用 Linux 系統執行。
    
    1. 編譯程式
    請於此目錄執行：make`
            .split("\n")
            .map((line) => line.trim())
            .join("\n") + "\n";
    if (cFiles.length) {
        readme += "\n";
        readme += "2. 執行程式\n";
        readme += "分別執行" + cFiles.map((f) => `\t./${f.split(".")[0]}`).join(", ");
    }

    return readme;
}

module.exports = make;
