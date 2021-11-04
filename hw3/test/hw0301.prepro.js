module.exports = (output) => {
    output.stdout = output.stdout.toLowerCase();
    if (output.code !== 0 || /error|fail|exception|invalid|wrong/.test(output.stdout)) return "!ERROR";
    return output.stdout.replace(/[^\d\s]/g, "").replace(/\s\s*/g, " ");
};
