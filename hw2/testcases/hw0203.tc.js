// use testcase-gen package

function p(n) {
    return n.toString().padStart(2, "0");
}

const rules = [
    {
        name: "Range: Same Day (2021/10/05)",
        generator: () => {
            let sHour = Math.floor(Math.random() * 26);
            let sMinute = Math.floor(Math.random() * 61);
            let eHour = Math.floor(Math.random() * 26);
            let eMinute = Math.floor(Math.random() * 61);
            return `2021/10/05 ${p(sHour)}:${p(sMinute)}\n2021/10/05 ${p(eHour)}:${p(eMinute)}`;
        },
        repeat: 300,
    },
    {
        name: "Range: 2 Days (2021/10/05,06)",
        generator: () => {
            let sDay = Math.floor(Math.random() * 33);
            let sHour = Math.floor(Math.random() * 26);
            let sMinute = Math.floor(Math.random() * 61);
            let eDay = sDay + 1;
            let eHour = Math.floor(Math.random() * 26);
            let eMinute = Math.floor(Math.random() * 61);
            return `2021/10/${p(sDay)} ${p(sHour)}:${p(sMinute)}\n2021/10/${p(eDay)} ${p(eHour)}:${p(eMinute)}`;
        },
        repeat: 300,
    },
    {
        name: "Range: 3 ~ 7 Days (2021/10/05+)",
        generator: () => {
            let sDay = Math.floor(Math.random() * 33);
            let sHour = Math.floor(Math.random() * 26);
            let sMinute = Math.floor(Math.random() * 61);
            let eDay = sDay + 3 + Math.floor(Math.random() * 5);
            let eHour = Math.floor(Math.random() * 26);
            let eMinute = Math.floor(Math.random() * 61);
            return `2021/10/${p(sDay)} ${p(sHour)}:${p(sMinute)}\n2021/10/${p(eDay)} ${p(eHour)}:${p(eMinute)}`;
        },
        repeat: 300,
    },
    {
        name: "Range: Same Month (2021/10)",
        generator: () => {
            let sDay = Math.floor(Math.random() * 33);
            let sHour = Math.floor(Math.random() * 24);
            let sMinute = Math.floor(Math.random() * 60);
            let eDay = Math.floor(Math.random() * 33);
            let eHour = Math.floor(Math.random() * 24);
            let eMinute = Math.floor(Math.random() * 60);
            return `2021/10/${p(sDay)} ${p(sHour)}:${p(sMinute)}\n2021/10/${p(eDay)} ${p(eHour)}:${p(eMinute)}`;
        },
        repeat: 300,
    },
    {
        name: "Range: Same Year (2021)",
        generator: () => {
            const d = [31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31];
            let sMonth = Math.floor(Math.random() * 14);
            let sDay = Math.floor(Math.random() * d[sMonth]);
            let sHour = Math.floor(Math.random() * 24);
            let sMinute = Math.floor(Math.random() * 60);
            let eMonth = Math.floor(Math.random() * 14);
            let eDay = Math.floor(Math.random() * d[eMonth]);
            let eHour = Math.floor(Math.random() * 24);
            let eMinute = Math.floor(Math.random() * 60);
            return `2021/${p(sMonth)}/${p(sDay)} ${p(sHour)}:${p(sMinute)}\n2021/${p(eMonth)}/${p(eDay)} ${p(eHour)}:${p(eMinute)}`;
        },
        repeat: 300,
    },
    {
        name: "Range: 1000000 Years",
        generator: () => {
            let sYear = Math.floor(Math.random() * 1000000);
            let sMonth = Math.floor(Math.random() * 12) + 1;
            let sDay = Math.floor(Math.random() * 28) + 1;
            let sHour = Math.floor(Math.random() * 24);
            let sMinute = Math.floor(Math.random() * 60);
            let eYear = sYear + Math.floor(Math.random() * 1000000);
            let eMonth = Math.floor(Math.random() * 12);
            let eDay = Math.floor(Math.random() * 28);
            let eHour = Math.floor(Math.random() * 24);
            let eMinute = Math.floor(Math.random() * 60);
            return `${sYear}/${p(sMonth)}/${p(sDay)} ${p(sHour)}:${p(sMinute)}\n${eYear}/${p(eMonth)}/${p(eDay)} ${p(eHour)}:${p(eMinute)}`;
        },
        repeat: 1000,
    },
    {
        name: "Range: MAX (2147483647 Years)",
        text: "1/01/01 00:00\n2147483647/12/31 23:59",
    },
];

module.exports = rules;
