// use testcase-gen package

function wordCount() {
    return Math.floor(Math.random() * 10000000) + 1;
}

function serviceLevel() {
    return Math.floor(Math.random() * 3) + 1;
}

function deliveryTime() {
    return Math.floor(Math.random() * 4) + 1;
}

const rules = [
    {
        name: "Testcases",
        generator: () => `${wordCount()} ${serviceLevel()} ${deliveryTime()}`,
        repeat: 1000,
    },
];

module.exports = rules;
