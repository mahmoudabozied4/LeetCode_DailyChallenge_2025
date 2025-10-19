/**
 * @param {string} s
 * @param {number} a
 * @param {number} b
 * @return {string}
 */
var findLexSmallestString = function (s, a, b) {
    let ans = s;
    const vis = new Set();

    const add = (str, a) => {
        let chars = str.split('');
        for (let i = 1; i < chars.length; i += 2) {
            let digit = parseInt(chars[i], 10);
            chars[i] = ((digit + a) % 10).toString();
        }
        return chars.join('');
    };

    const rotate = (str, b) => {
        const n = str.length;
        const k = b % n;
        return str.substring(n - k) + str.substring(0, n - k);
    };

    const dfs = (currentS) => {
        if (vis.has(currentS)) {
            return;
        }

        vis.add(currentS);

        if (currentS < ans) {
            ans = currentS;
        }
        dfs(add(currentS, a));

        dfs(rotate(currentS, b));
    };

    dfs(s);

    return ans;
};