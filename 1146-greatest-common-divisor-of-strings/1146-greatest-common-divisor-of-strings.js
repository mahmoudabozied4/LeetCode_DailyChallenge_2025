/**
 * Calculates the Least Common Multiple (LCM) of two numbers using an iterative approach.
 * @param {number | bigint} num1 The first number.
 * @param {number | bigint} num2 The second number.
 * @returns {bigint} The LCM of num1 and num2.
 */
function lcm(num1, num2) {
    let a = BigInt(num1);
    let b = BigInt(num2);
    if (a > b) {
        const old_a = a;
        while (a % b !== 0n) {
            a += old_a;
        }
        return a;
    } else {
        const old_b = b;
        while (b % a !== 0n) {
            b += old_b;
        }
        return b;
    }
}

/**
 * Calculates the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm.
 * @param {number} a The first number.
 * @param {number} b The second number.
 * @returns {number} The GCD of a and b.
 */
function gcd(a, b) {
    if (b) {
        return gcd(b, a % b);
    } else {
        return Math.abs(a);
    }
}

/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */

var gcdOfStrings = function (str1, str2) {
    let str1PlusStr2 = str1 + str2; // O(n + m)
    let str2PlusStr1 = str2 + str1; // O(n + m)
    if (str1PlusStr2 !== str2PlusStr1) {
        return ""
    }
    let a = gcd(str1.length , str2.length);
    return str1.substring(0 , a)
};
