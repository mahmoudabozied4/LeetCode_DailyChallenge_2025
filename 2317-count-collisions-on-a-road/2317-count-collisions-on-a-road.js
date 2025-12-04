var countCollisions = function (directions) {
    const length = directions.length;

    let leftBoundary = 0;
    while (leftBoundary < length && directions[leftBoundary] === 'L') {
        leftBoundary++;
    }

    let rightBoundary = length - 1;
    while (rightBoundary >= 0 && directions[rightBoundary] === 'R') {
        rightBoundary--;
    }

    let collisionCount = rightBoundary - leftBoundary + 1;

    for (let i = leftBoundary; i <= rightBoundary; i++) {
        if (directions[i] === 'S') {
            collisionCount--;
        }
    }

    return Math.max(0, collisionCount);
};
