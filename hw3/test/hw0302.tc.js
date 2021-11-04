const MAX = 2 ** 31 - 1;

const rules = [
    {
        name: "Example",
        text: "1234 456",
    },
    {
        name: "Acceptable 2x [0]",
        text: "0 0",
    },
    {
        name: "Acceptable 1x [0] 1x [1 ~ MAX]",
        generator: () => {
            const a = 0;
            const b = Math.floor(Math.random() * MAX) + 1;
            return Math.random() < 0.5 ? `${a} ${b}` : `${b} ${a}`;
        },
        repeat: 20,
    },
    {
        name: "Acceptable 2x [1 ~ MAX/2]",
        generator: () => {
            const a = Math.floor((Math.random() * MAX) / 2) + 1;
            const b = Math.floor((Math.random() * MAX) / 2) + 1;
            return `${a} ${b}`;
        },
        repeat: 30,
    },
    {
        name: "Unacceptable 1x [-MAX ~ -1] 1x [0 ~ MAX]",
        generator: () => {
            const a = Math.floor(Math.random() * (MAX + 1));
            const b = -(Math.floor(Math.random() * MAX) + 1);
            return Math.random() < 0.5 ? `${a} ${b}` : `${b} ${a}`;
        },
        repeat: 30,
    },
    {
        name: "Unacceptable result > MAX (= MAX + 1)",
        generator: () => {
            const sum = MAX + 1;
            const a = Math.floor(Math.random() * sum);
            const b = sum - a;
            return Math.random() < 0.5 ? `${a} ${b}` : `${b} ${a}`;
        },
        repeat: 20,
    },
];

module.exports = rules;
