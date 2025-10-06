function merge(intervals: number[][]): number[][] {
    intervals.sort((a, b) => a[0] - b[0]);
    const mergedIntervals = [];
    let workingInterval = intervals[0];

    for (let i = 1; i < intervals.length; i++) {
        let curInterval = intervals[i];
        if (curInterval[0] <= workingInterval[1]) {
            workingInterval[1] = Math.max(workingInterval[1], curInterval[1]);
        } else {
            mergedIntervals.push(workingInterval);
            workingInterval = curInterval;
        }
    }
    mergedIntervals.push(workingInterval);
    return mergedIntervals;
};