function* gen() {
    let i = 3;
    while (true) yield i++;
}

const g = gen();

const rules = [
    {
        name: "Example",
        text: "2",
    },
    {
        name: "3 ~ 100",
        generator: () => g.next().value.toString(),
        repeat: 98,
    },
    {
        name: "100000000",
        text: "100000000",
    },
];

module.exports = rules;
