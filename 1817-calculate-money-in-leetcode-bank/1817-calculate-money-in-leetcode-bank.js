/**
 * @param {number} n
 * @return {number}
 */
var totalMoney = function (n) {
    const weeks = Math.floor(n / 7);
    const low = 28;
    const high = 28 + 7 * (weeks - 1);
    let res = (weeks * (low + high)) / 2;

    const monday = weeks + 1;
    for (let i = 0; i < n % 7; i++) {
        res += i + monday;
    }

    return res;
};