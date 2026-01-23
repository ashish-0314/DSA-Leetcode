class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int lsum = 0 ;
        for(int i = 0 ; i< nums.size() ; i++){
            int rsum = sum-lsum-nums[i];
            if(lsum==rsum) return i;
            lsum+=nums[i];
        }
        return -1;
    }
};