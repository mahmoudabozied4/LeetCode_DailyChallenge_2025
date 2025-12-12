/**
 * @param {number} numberOfUsers
 * @param {string[][]} events
 * @return {number[]}
 */
var countMentions = function(numberOfUsers, events) {
    const online = 0,  offline = 1,  message = 2;

    let timeline = [];

    for (let event of events) {
        const cur = event[0];
        const ts = parseInt(event[1]);
        const data = event[2];
        if (cur === "MESSAGE") {
            timeline.push({ time: ts, type: message, payload: data });
        } else {
            const uid = parseInt(data);
            timeline.push({ time: ts, type: offline, userId: uid });
            timeline.push({ time: ts + 60, type: online, userId: uid });
        }
    }

    timeline.sort((a, b) => {
        if (a.time !== b.time) return a.time - b.time;
        return a.type - b.type;
    });

    let explicitMentions = new Array(numberOfUsers).fill(0) ,  missedHereCount = new Array(numberOfUsers).fill(0);

    let offlineStartVal = new Array(numberOfUsers).fill(0);
    let isTrackedOffline = new Array(numberOfUsers).fill(false);
    let onlineThreshold = new Array(numberOfUsers).fill(0);

    let globalAllCount = 0;
    let globalHereCount = 0;

    // 4. Process Timeline
    for (let ev of timeline) {
        if (ev.type === online) {
            const uid = ev.userId;
            if (isTrackedOffline[uid] && ev.time >= onlineThreshold[uid]) {
                let missed = globalHereCount - offlineStartVal[uid];
                missedHereCount[uid] += missed;
                isTrackedOffline[uid] = false;
            }
        }
        else if (ev.type === offline) {
            const uid = ev.userId;
            onlineThreshold[uid] = Math.max(onlineThreshold[uid], ev.time + 60);

            if (!isTrackedOffline[uid]) {
                isTrackedOffline[uid] = true;
                offlineStartVal[uid] = globalHereCount;
            }
        }
        else {
            const tokens = ev.payload.split(' ');
            for (let token of tokens) {
                if (token === "ALL") {
                    globalAllCount++;
                } else if (token === "HERE") {
                    globalHereCount++;
                } else {
                    const uid = parseInt(token.slice(2));
                    explicitMentions[uid]++;
                }
            }
        }
    }

    const result = [];
    for (let i = 0; i < numberOfUsers; i++) {
        if (isTrackedOffline[i]) {
            missedHereCount[i] += (globalHereCount - offlineStartVal[i]);
        }
        let total = explicitMentions[i] + globalAllCount + (globalHereCount - missedHereCount[i]);
        result.push(total);
    }
    return result;
};