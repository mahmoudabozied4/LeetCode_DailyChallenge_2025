class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mx = 0  ;
        for(int i = 0 ; i <= nums.size() ; i++) mx^=i;
        for(int i = 0 ; i < nums.size() ; i++) mx^=nums[i];
        return mx ;
    }
};