
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int> > mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            auto &workingInterval = mergedIntervals.back(), &curInterval = intervals[i];

            if (curInterval[0] <= workingInterval[1]) {
                workingInterval[1] = max(workingInterval[1], curInterval[1]);
            } else {
                mergedIntervals.push_back(curInterval);
            }
        }
        return mergedIntervals;
    }
};