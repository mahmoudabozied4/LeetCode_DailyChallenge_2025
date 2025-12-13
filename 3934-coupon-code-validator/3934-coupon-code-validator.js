/**
 * @param {string[]} code
 * @param {string[]} businessLine
 * @param {boolean[]} isActive
 * @return {string[]}
 */
var validateCoupons = function(code, businessLine, isActive) {
      const order = ["electronics", "grocery", "pharmacy", "restaurant"];
  const priority = new Map(order.map((b, i) => [b, i]));

  const valid = [];
  const re = /^[A-Za-z0-9_]+$/;

  for (let i = 0; i < code.length; i++) {
    if (!isActive[i]) continue;
    if (!priority.has(businessLine[i])) continue;
    if (code[i].length === 0) continue;
    if (!re.test(code[i])) continue;

    valid.push({ code: code[i], businessLine: businessLine[i] });
  }

  valid.sort((a, b) => {
    const pa = priority.get(a.businessLine);
    const pb = priority.get(b.businessLine);
    if (pa !== pb) return pa - pb;

     if (a.code < b.code) return -1;
    if (a.code > b.code) return 1;
    return 0;
  });

  return valid.map(x => x.code);
};