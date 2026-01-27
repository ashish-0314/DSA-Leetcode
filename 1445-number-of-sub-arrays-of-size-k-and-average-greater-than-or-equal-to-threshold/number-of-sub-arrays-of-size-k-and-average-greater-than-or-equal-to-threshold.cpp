class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int sum = 0;
        int avg = k * threshold;
        int cnt = 0 ;
        for(int i = 0 ; i < k ; i++){
            sum+=nums[i];
        }
        if(sum>=avg) cnt++;
        for(int i = k ; i< nums.size() ; i++){
            sum+=nums[i] - nums[i-k];
            if(sum>=avg) cnt++;
        }
        return cnt;
    }
};