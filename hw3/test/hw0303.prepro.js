module.exports = (output) => {
    output.stdout = output.stdout.toLowerCase();
    if (output.code !== 0 || /error|fail|exception|invalid|wrong/.test(output.stdout)) return "!ERROR";
    return output.stdout.match(/start|s\d|final/g, "").join(" ");
};
