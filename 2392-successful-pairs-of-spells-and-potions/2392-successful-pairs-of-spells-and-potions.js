/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
var successfulPairs = function (spells, potions, success) {
    let result = []

    potions.sort((a, b) => a - b)

    for (const spell of spells) {
        let s = 0, e = potions.length - 1
        let count = potions.length

        while (s <= e) {
            let m = Math.floor((s + e) / 2);

            if (spell * potions[m] >= success) {
                e = m - 1;
                count = m;
            } else {
                s = m + 1;
            }
        }
        result.push(potions.length - count);
    }
    return result;
};