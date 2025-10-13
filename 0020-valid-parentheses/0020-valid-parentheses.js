/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  const stack = [];
  const bracketMap = new Map([
    [')', '('],
    ['}', '{'],
    [']', '[']
  ]);
  for (const char of s) {
    if (bracketMap.has(char)) {
      if (stack.length === 0 || stack[stack.length - 1] !== bracketMap.get(char)) {
        return false;
      }
      stack.pop();
    } else {
      stack.push(char);
    }
  }
  return stack.length === 0;
};