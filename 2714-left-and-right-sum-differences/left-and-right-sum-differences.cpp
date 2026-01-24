class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int tsum = accumulate(nums.begin(),nums.end(),0);
        int lsum = 0 ;
        vector<int> res;
        for(int i = 0 ; i< nums.size() ; i++){
            int rsum = tsum -lsum -nums[i];
            res.push_back(abs(lsum-rsum));
            lsum+=nums[i];
        }
        return res;
    }
};