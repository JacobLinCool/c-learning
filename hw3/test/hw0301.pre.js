module.exports = (output) => {
    output.stdout = output.stdout.toLowerCase();
    if (output.code !== 0 || output.stdout.includes("error")) return "!ERROR";
    return output.stdout.replace(/[^\d\s]/g, "").replace(/\s\s*/g, " ");
};
