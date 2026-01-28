class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 , right = 0 , maxLen = 0 , zeroCnt = 0 ;
        int n = nums.size();
        while(right<n){
            if(nums[right]==0) zeroCnt++;
            while(zeroCnt>k){
                if(nums[left]==0) zeroCnt--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};