function* gen(start) {
    let i = start;
    while (true) {
        yield i;
        i += 2;
    }
}

const odd = gen(1);
const even = gen(2);

const rules = [
    {
        name: "Accepted 1 ~ 99 Odd",
        generator: () => `${odd.next().value}`,
        repeat: 50,
    },
    {
        name: "Rejected 2 ~ 100 Even",
        generator: () => `${even.next().value}`,
        repeat: 50,
    },
    {
        name: "Rejected 0",
        text: "0",
    },
    {
        name: "Rejected 101",
        text: "101",
    },
    {
        name: "Rejected -1",
        text: "-1",
    },
];

module.exports = rules;
