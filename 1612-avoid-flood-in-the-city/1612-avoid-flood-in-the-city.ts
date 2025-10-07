function avoidFlood(rains: number[]): number[] {
      const n = rains.length;
  const mp = new Map();
  const sunnyDays = [];
  const ans = new Array(n).fill(0);

  for (let day = 0; day < n; day++) {
    const lake = rains[day];

    if (lake > 0) {
      if (mp.has(lake)) {
        const lastRainyDayForLake = mp.get(lake);

        let bestReplacement = -1;
        for (let sunnyDayIndex = 0; sunnyDayIndex < sunnyDays.length; sunnyDayIndex++) {
          if (sunnyDays[sunnyDayIndex] > lastRainyDayForLake) {
            if (bestReplacement === -1 || sunnyDays[sunnyDayIndex] < sunnyDays[bestReplacement]) {
              bestReplacement = sunnyDayIndex;
            }
          }
        }

        if (bestReplacement === -1) {
          return [];
        }

        ans[ sunnyDays[bestReplacement]] = lake;
        sunnyDays.splice(bestReplacement, 1);
      }

      mp.set(lake, day);
      ans[day] = -1;
    } else {
      sunnyDays.push(day);
    }
  }  
  for (const it of sunnyDays) {
    ans[it] = 1;
  }
  return ans;

};