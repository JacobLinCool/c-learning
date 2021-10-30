// use testcase-gen package

const rules = [
    {
        name: "Range: 10000 Years",
        generator: () => {
            let start_year = Math.floor(Math.random() * 10000);
            let start_month = Math.floor(Math.random() * 12) + 1;
            let start_day = Math.floor(Math.random() * 28) + 1;
            let start_hour = Math.floor(Math.random() * 24);
            let start_minute = Math.floor(Math.random() * 60);
            let end_year = start_year + Math.floor(Math.random() * 10000);
            let end_month = Math.floor(Math.random() * 12);
            let end_day = Math.floor(Math.random() * 28);
            let end_hour = Math.floor(Math.random() * 24);
            let end_minute = Math.floor(Math.random() * 60);
            return `${start_year}/${start_month}/${start_day} ${start_hour.toString().padStart(2, "0")}:${start_minute
                .toString()
                .padStart(2, "0")}\n${end_year}/${end_month}/${end_day} ${end_hour.toString().padStart(2, "0")}:${end_minute.toString().padStart(2, "0")}`;
        },
        repeat: 1000,
    },
    {
        name: "Range: 1000000 Years",
        generator: () => {
            let start_year = Math.floor(Math.random() * 1000000);
            let start_month = Math.floor(Math.random() * 12) + 1;
            let start_day = Math.floor(Math.random() * 28) + 1;
            let start_hour = Math.floor(Math.random() * 24);
            let start_minute = Math.floor(Math.random() * 60);
            let end_year = start_year + Math.floor(Math.random() * 1000000);
            let end_month = Math.floor(Math.random() * 12);
            let end_day = Math.floor(Math.random() * 28);
            let end_hour = Math.floor(Math.random() * 24);
            let end_minute = Math.floor(Math.random() * 60);
            return `${start_year}/${start_month}/${start_day} ${start_hour.toString().padStart(2, "0")}:${start_minute
                .toString()
                .padStart(2, "0")}\n${end_year}/${end_month}/${end_day} ${end_hour.toString().padStart(2, "0")}:${end_minute.toString().padStart(2, "0")}`;
        },
        repeat: 1000,
    },
    {
        name: "Range: MAX (2147483647 Years)",
        text: "1/1/1 00:00\n2147483647/12/31 23:59",
    },
];

module.exports = rules;
