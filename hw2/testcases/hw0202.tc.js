// use testcase-gen package

function gen() {
    return Math.floor(-100000000 + Math.random() * 200000000) || 1;
}

const rules = [
    {
        name: "Testcases",
        generator: () => `${gen()}, ${gen()}\n${gen()}, ${gen()}`,
        repeat: 1000,
    },
];

module.exports = rules;
