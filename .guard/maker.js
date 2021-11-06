const fs = require("fs");
const path = require("path");
const util = require("util");
const exec = util.promisify(require("child_process").exec);
const { findFilesByRegex } = require("./utils");
const { mdToPdf } = require("md-to-pdf");

async function make(homework) {
    log("=====");
    log(`Generating resources of ${homework}`);
    const cSources = findFilesByRegex(path.join(__dirname, "../", homework), /hw.+?\.c$/);

    //#region Create Makefile
    log("Creating Makefile... ");
    const makefile = createMakefile(cSources);
    fs.writeFileSync(path.join(__dirname, "../", homework, "Makefile"), makefile, "utf8");
    log(`Makefile Created. \n---\n${makefile}\n---`);
    //#endregion

    //#region Homwwork MD -> PDF
    log("Converting Markdown to PDF... ");
    const mdFiles = findFilesByRegex(path.join(__dirname, "../", homework), /hw.+?\.md$/);
    for (const mdFile of mdFiles) {
        log(`Converting ${path.basename(mdFile)} to PDF`);
        await MDtoPDF(mdFile, mdFile.replace(/\.md$/, ".pdf"));
    }
    log(`Markdown to PDF Conversion Completed.`);
    //#endregion

    const hwPDFs = findFilesByRegex(path.join(__dirname, "../", homework), /hw.+?\.pdf$/);

    //#region Create README.md and transform it to PDF
    if (!fs.existsSync(path.join(__dirname, "../", homework, "README.md"))) {
        log("Creating README.md... ");
        const readme = createREADME(cSources, hwPDFs, homework.match(/hw(\d{1})/)[1]);
        fs.writeFileSync(path.join(__dirname, "../", homework, "README.md"), readme, "utf8");
        log(`README.md Created. \n---\n${readme}\n---`);
    }
    if (fs.existsSync(path.join(__dirname, "../", homework, "README.md"))) {
        log("Converting README.md to PDF... ");
        await MDtoPDF(path.join(__dirname, "../", homework, "README.md"), path.join(__dirname, "../", homework, "README.pdf"));
        log(`README.md to PDF Conversion Completed.`);
    }
    //#endregion

    //#region ZIP
    if (process.platform === "win32") {
        log("Windows does not support zip command.");
    } else {
        const zipContents = ["README.pdf", "Makefile"].concat(cSources.map((f) => path.basename(f))).concat(hwPDFs.map((f) => path.basename(f)));
        const { stdout, stderr } = await exec(`cd ${homework} && zip ${homework}.zip ${zipContents.join(" ")}`);
        log(`STDOUT: \n${stdout}`);
        if (stderr) log(`STDERR: \n${stderr}`);
        if (fs.existsSync(path.join(__dirname, "../", homework, `${homework}.zip`))) {
            if (!fs.existsSync(path.join(__dirname, "../", "dist"))) fs.mkdirSync(path.join(__dirname, "../", "dist"));
            fs.renameSync(path.join(__dirname, "../", homework, `${homework}.zip`), path.join(__dirname, "../", "dist", `${homework}.zip`));
            log(`${homework}.zip is generated.`);
        }
    }
    //#endregion
}

function createMakefile(cSources) {
    cSources = cSources.map((f) => path.basename(f));
    let makefile = "";
    makefile += "all: \n";
    makefile += cSources.map((f) => `\tgcc -static -lm -O2 -std=gnu99 -o ${f.replace(/\.c$/, "")} ${f}`).join("\n");
    makefile += "\n";
    makefile += "clean: \n";
    makefile += cSources.map((f) => `\trm ${f.split(".")[0]}`).join("\n");
    makefile += "\n";
    return makefile;
}

function createREADME(cSources, hwPDFs, hwID = "") {
    let readme = `# 程式設計一 Homework ${hwID}

        作者：師大資工 114 林振可 (41047029S)

        建議使用 Linux 系統執行。

        ## 1. 編譯程式

        請於此目錄執行：

        \`\`\`bash
        make
        \`\`\`

        \`make\` 應產生 ${cSources.length} 個可執行檔。`
        .split("\n")
        .map((line) => line.trim())
        .join("\n");
    readme += "\n";
    if (cSources.length) {
        readme += `\n## 2. 執行程式\n\n分別執行：\n\n`;
        readme += cSources.map((f) => `\`\`\`bash\n./${path.basename(f).replace(/\.c$/, "")}\n\`\`\``).join("\n\n");
        readme += "\n";
    }
    if (hwPDFs.length) {
        readme += `\n## 3. 手寫作業\n\n作業包含 ${hwPDFs.length} 個手寫作業。\n\n檔案：\n\n`;
        readme += hwPDFs.map((f) => `* **${path.basename(f)}**`).join("\n");
        readme += "\n";
    }
    return readme;
}

async function MDtoPDF(filepath, distpath) {
    try {
        const pdf = await mdToPdf(
            { path: filepath },
            {
                highlight_style: "nord",
                css: `
                body { font-family: "Noto Sans TC", sans-serif !important; background: #ECEFF4 !important; color: #2E3440 !important; } 
                pre > code, code, code:not([class]) { color: #ECEFF4 !important; background: #2E3440 !important; font-family: "MesloLGS NF", "Cascadia Code", "Ubuntu Mono", monospace !important; }
                td, th { border: 1px solid #D8DEE9 !important; }
                thead > tr { background: #ECEFF4 !important; color: #2E3440 !important; }
                tbody > tr:nth-child(odd) { background: #ECEFF4 !important; color: #2E3440 !important; }
                tbody > tr:nth-child(even) { background: #E5E9F0 !important; color: #2E3440 !important; }
                `,
                pdf_options: {
                    format: "A4",
                    orientation: "portrait",
                    margin: "20mm",

                    headerTemplate: `<img style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; z-index: -1;" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mN88/7LfwAJbgPQ0oMMRAAAAABJRU5ErkJggg==">`,
                    footerTemplate: `<span style="width: 100%; text-align: right; color: #2E3440; font-size: 10px; padding: 24px;">41047029S</span>`,
                    printBackground: true,
                    displayHeaderFooter: true,
                },
            }
        );
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
