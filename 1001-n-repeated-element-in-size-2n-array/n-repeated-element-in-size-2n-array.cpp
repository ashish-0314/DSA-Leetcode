class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        sort(nums.begin(),nums.end());
        int cnt = 1 ;
        for(int i = 1 ; i<= n ; i++ ){
            if(nums[i]==nums[i-1]) cnt++;
            if(cnt==n) return nums[i];
        }
        return nums[n];
    }
};