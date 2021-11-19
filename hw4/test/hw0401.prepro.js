const errors = ["error", "invalid", "wrong", "incorrect", "unexpected"];

module.exports = ({ stdout, code }) => {
    stdout = stdout.toLowerCase().trim();
    if (errors.some((e) => stdout.includes(e)) || code !== 0) {
        return "!ERROR";
    }
    return stdout.replace(/[^*\s]/gi, "").trim();
};
