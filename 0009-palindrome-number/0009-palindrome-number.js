/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  if (x < 0 ) return false;
  let xString = String(x);
  let xStringReversed = xString.split('').reverse().join('')
  return xStringReversed === xString;
};