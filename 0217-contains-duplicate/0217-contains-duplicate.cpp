class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto a = nums;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        return (nums.size() > a.size());
    }
};