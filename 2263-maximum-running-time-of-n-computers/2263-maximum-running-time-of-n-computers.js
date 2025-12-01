var maxRunTime = function(n, batteries) {
    let total = 0n;
    for (const b of batteries) {
        total += BigInt(b);
    }

    let left = 0n;
    let right = total / BigInt(n);

    const canRun = (time) => {
        let available = 0n;
        for (const b of batteries) {
            const bb = BigInt(b);
            available += (bb < time ? bb : time);
        }
        return available >= time * BigInt(n);
    };

    while (left < right) {
        const mid = (left + right + 1n) / 2n;
        if (canRun(mid)) left = mid;
        else right = mid - 1n;
    }

    return Number(left);
};
