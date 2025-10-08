class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3,INT_MIN);
        dp[0]=0;
        for(auto & num : nums){
            vector<int> temp = dp;
            for(int r = 0 ; r < 3 ; r++){
                if(temp[r]>=0){
                    int new_remi = (r+num)%3;
                    dp[new_remi]=max(dp[new_remi],temp[r]+num);
                }
            }
        }
        return dp[0];
    }
};