const rules = [
    {
        name: "Example",
        text: "5 3",
    },
    {
        name: "Acceptable 1x [1] 1x [1 ~ 50]",
        generator: () => {
            const a = 1;
            const b = Math.floor(Math.random() * 50) + 1;
            return Math.random() < 0.5 ? `${a} ${b}` : `${b} ${a}`;
        },
        repeat: 20,
    },
    {
        name: "Acceptable 2x [2 ~ 50]",
        generator: () => {
            const w = Math.floor(Math.random() * 49) + 2;
            const h = Math.floor(Math.random() * 49) + 2;
            return `${w} ${h}`;
        },
        repeat: 30,
    },
    {
        name: "Unacceptable 1x [-99 ~ 0] 1x [1 ~ 100]",
        generator: () => {
            const a = -Math.floor(Math.random() * 100);
            const b = Math.floor(Math.random() * 100) + 1;
            return Math.random() < 0.5 ? `${a} ${b}` : `${b} ${a}`;
        },
        repeat: 50,
    },
];

module.exports = rules;
