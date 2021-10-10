const fs = require("fs");
const path = require("path");
const { mdToPdf } = require("md-to-pdf");

(async () => {
    const filepath = path.join(__dirname, "../", "hw1", "hw0105", "hw0105.md");
    const pdf = await mdToPdf({ path: filepath }, { highlight_style: "nord" }).catch(console.error);
    if (pdf) fs.writeFileSync("pdf.pdf", pdf.content);
})();
