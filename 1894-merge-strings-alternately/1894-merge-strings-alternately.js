/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function (word1, word2) {
    let ans = '';
    let word1Idx = 0;
    let word2Idx = 0;

    while (word1Idx < word1.length && word2Idx < word2.length) {
        ans += word1[word1Idx++];
        ans += word2[word2Idx++];
    }

    if (word1Idx < word1.length) {
        ans += word1.substring(word1Idx);
    }

    if (word2Idx < word2.length) {
        ans += word2.substring(word2Idx);
    }

    return ans;
};

// console.log(mergeAlternately("12" , "456"))
