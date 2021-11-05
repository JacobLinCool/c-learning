function acceptable_year() {
    return (1900 + Math.floor(Math.random() * (2 ** 16))).toString();
}

function acceptable_temparature() {
    return (-273.15 + Math.random() * (2 ** 16 + 273.15)).toFixed(1);
}

const rules = [
    {
        name: "Example",
        text: "2000 29.5 2001 29.7 2002 29.6 2003 31.2 2004 30.5 -1 2022",
    },
    {
        name: "2 ~ 100 data points",
        generator: () => {
            const p = 2 + Math.floor(Math.random() * 99);
            let str = "";
            for (let i = 0; i < p; i++) str += `${acceptable_year()} ${acceptable_temparature()} `;
            str += "-1 " + acceptable_year();
            return str;
        },
        repeat: 100,
    },
];

module.exports = rules;
