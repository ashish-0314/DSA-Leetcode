class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxiIdx =-1;
        int maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]>maxi){
                maxi = max(maxi,nums[i]);
                maxiIdx =i;
            }
        }
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] != maxi && maxi < 2*nums[i]) return -1;
        }
        return maxiIdx;
    }
};