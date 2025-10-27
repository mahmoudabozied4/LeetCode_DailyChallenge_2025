/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function (bank) {
    const countOnes = (s) => {
        let cnt = 0;
        for (let c of s) {
            if (c === '1') cnt += 1;
        }
        return cnt;
    };

    let prev = countOnes(bank[0]);
    let res = 0;

    for (let i = 1; i < bank.length; i++) {
        let curr = countOnes(bank[i]);
        if (curr > 0) {
            res += prev * curr;
            prev = curr;
        }
    }

    return res;
};