function maximumTotalDamage(power) {
    power.sort((a, b) => a - b);
    const arraySize = power.length;
    const powerFrequency = new Map();
    const memo = new Array(arraySize).fill(0);
    const nextValidIndex = new Array(arraySize);
    const powers = power.slice();

    for (let i = 0; i < arraySize; i++) {
        powerFrequency.set(powers[i], (powerFrequency.get(powers[i]) || 0) + 1);
    }

    for (let i = 0; i < arraySize; i++) {
        let target = powers[i] + 3;
        let left = i + 1, right = arraySize;
        while (left < right) {
            let mid = Math.floor((left + right) / 2);
            if (powers[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        nextValidIndex[i] = left;
    }

    function calculateMaxDamage(index) {
        if (index >= arraySize) {
            return 0;
        }
        if (memo[index] !== 0) {
            return memo[index];
        }

        const currentPower = powers[index];
        const skipCurrentPower = calculateMaxDamage(index + (powerFrequency.get(currentPower) || 0));
        const takeCurrentPower = currentPower * (powerFrequency.get(currentPower) || 0) + calculateMaxDamage(nextValidIndex[index]);

        memo[index] = Math.max(skipCurrentPower, takeCurrentPower);
        return memo[index];
    }

    return calculateMaxDamage(0);
}
