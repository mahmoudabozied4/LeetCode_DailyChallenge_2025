/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  const romanMap = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
  };

  let ans = 0, numeralLength = s.length;

  for (let i = 0; i < numeralLength; i++) {
    const currentValue = romanMap[s[i]], nextValue = romanMap[s[i + 1]];

    if (i < numeralLength - 1 && currentValue < nextValue) {
      ans -= currentValue;
    } else {
      ans += currentValue;
    }
  }
  return ans;
};
