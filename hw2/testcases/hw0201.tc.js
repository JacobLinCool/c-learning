// use testcase-gen package

function gen() {
    return Math.floor(-10000000 + Math.random() * 20000000) || 1;
}

const rules = [
    {
        name: "Testcases",
        generator: () => `${gen()}, ${gen()}, ${gen()}`,
        repeat: 1000,
    },
];

module.exports = rules;
