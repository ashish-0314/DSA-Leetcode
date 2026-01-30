class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int maxi = 1e9;
        for(int i = 0 ; i< nums.size() ; i++){
            int sum = 0;
            for(int j = i ; j< nums.size() ; j++){
                sum+=nums[j];
                if(j-i+1>=l && j-i+1 <=r && sum >0) maxi = min(maxi,sum);
            }
        }
        return (maxi==1e9) ? -1 : maxi;
    }
};