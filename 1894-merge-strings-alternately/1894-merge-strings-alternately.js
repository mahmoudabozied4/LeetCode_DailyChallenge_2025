/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function (word1, word2) {
    let ans ="";
    let lenWord1 = word1.length, lenWord2 = word2.length;
    let pointerWord1 = 0, pointerWord2 = 0;
    while (lenWord1 > 0 && lenWord2 > 0) {
        ans +=(word1[pointerWord1] + word2[pointerWord2]);
        lenWord1--
        lenWord2--
        pointerWord1++
        pointerWord2++
    }

    while (lenWord1>0) {
        lenWord1--;
        ans += (word1[pointerWord1++]);
    }

    while (lenWord2>0) {
        lenWord2--;
        ans += (word2[pointerWord2++]);
    }
    return ans;
};