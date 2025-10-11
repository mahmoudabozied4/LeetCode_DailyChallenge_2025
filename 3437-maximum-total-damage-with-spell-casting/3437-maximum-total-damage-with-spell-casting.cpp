class Solution {
    unordered_map<int, int> powerFrequency;
    vector<long long> memo;
    vector<int> powers, nextValidIndex;
    int arraySize;

    long long calculateMaxDamage(int index) {
        if (index >= arraySize) {
            return 0;
        }

        if (memo[index] != 0) {
            return memo[index];
        }
        long long skipCurrentPower = calculateMaxDamage(index + powerFrequency[powers[index]]);
        long long takeCurrentPower = static_cast<long long>(powers[index]) * powerFrequency[powers[index]] +
                                     calculateMaxDamage(nextValidIndex[index]);
        memo[index] = max(skipCurrentPower, takeCurrentPower);
        return memo[index];
    }
public:
    long long maximumTotalDamage(vector<int> &power) {
        sort(power.begin(), power.end());
        this->powers = power;
        arraySize = power.size();
        memo.resize(arraySize, 0);
        nextValidIndex.resize(arraySize);
        for (int i = 0; i < arraySize; ++i) {
            powerFrequency[powers[i]]++;
            nextValidIndex[i] = upper_bound(powers.begin() + i + 1, powers.end(), powers[i] + 2) - powers.begin();
        }
        return calculateMaxDamage(0);
    }
};