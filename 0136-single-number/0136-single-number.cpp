class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mx = 0 ; 
        for(auto it : nums) mx^=it;
        return mx;
    }
};