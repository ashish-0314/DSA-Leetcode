class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        for(int i = 0 ; i< k ; i++){
            sum+=nums[i];
        }
        double maxi = sum/k;
        for(int i = 0 ; i< nums.size()-k ; i++){
            sum = sum - nums[i] + nums[i+k];
            maxi= max(maxi , sum/k);
        }
        return maxi;
    }
};