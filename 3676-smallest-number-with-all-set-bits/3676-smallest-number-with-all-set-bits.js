/**
 * @param {number} n
 * @return {number}
 */
var smallestNumber = function(n) {
    let powerOfTwo = 1;
    while (powerOfTwo - 1 < n) {
        powerOfTwo <<= 1; 
    }
    return powerOfTwo - 1;
};