class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            long long rem = nums[i] % 3;
            if (rem != 0)
                ++ans;
        }
       return ans ;
    }
};