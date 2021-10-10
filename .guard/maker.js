const fs = require("fs");
const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);
const { mdToPdf } = require("md-to-pdf");

async function make(homework) {
    log("=====");
    log(`Generating resources of ${homework}`);
    const cFiles = fs.readdirSync(path.join(__dirname, "../", homework)).filter((f) => f.endsWith(".c"));
    const pdfFiles = fs.readdirSync(path.join(__dirname, "../", homework)).filter((f) => f.endsWith(".pdf"));

    // Makefile
    const makefile = createMakefile(cFiles);
    fs.writeFileSync(path.join(__dirname, "../", homework, "Makefile"), makefile);

    // README
    if (!fs.existsSync(path.join(__dirname, "../", homework, "README")))
        fs.writeFileSync(path.join(__dirname, "../", homework, "README"), createREADME(cFiles));

    // MD -> PDF
    if (fs.existsSync(path.join(__dirname, "../", homework, "README.md")))
        await MDtoPDF(path.join(__dirname, "../", homework, "README.md"), path.join(__dirname, "../", homework, "README.pdf"));
    const mdFiles = fs.readdirSync(path.join(__dirname, "../", homework)).filter((f) => f.endsWith(".md"));
    for (const mdFile of mdFiles)
        await MDtoPDF(path.join(__dirname, "../", homework, mdFile), path.join(__dirname, "../", homework, mdFile.replace(".md", ".pdf")));

    // ZIP
    const { stdout, stderr } = await exec(`cd ${homework} && zip ${homework}.zip README Makefile ${cFiles.join(" ")} ${pdfFiles.join(" ")}`);
    log(`STDOUT: \n${stdout}`);
    log(`STDERR: \n${stderr || "No Error. Excellent!"}`);
    if (fs.existsSync(path.join(__dirname, "../", homework, `${homework}.zip`))) {
        if (!fs.existsSync(path.join(__dirname, "../", "dist"))) fs.mkdirSync(path.join(__dirname, "../", "dist"));
        fs.renameSync(path.join(__dirname, "../", homework, `${homework}.zip`), path.join(__dirname, "../", "dist", `${homework}.zip`));
        log(`${homework}.zip is generated.`);
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

async function MDtoPDF(filepath, distpath) {
    try {
        const pdf = await mdToPdf({ path: filepath }, { highlight_style: "nord" });
        if (pdf) fs.writeFileSync(distpath, pdf.content);
        else throw new Error("PDF Conversion Failed.");
    } catch (err) {
        log(err);
    }
}

function log(...msg) {
    console.log("[Maker]", ...msg);
}

module.exports = make;
