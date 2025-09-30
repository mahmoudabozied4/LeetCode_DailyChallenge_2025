class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            int cur = nums[i];
            int n = 0;
            while (cur > 0) {
                n++;cur/=10;
            }
            ans += n%2 == 0 ;
        }
        return ans ;
    }
    
};