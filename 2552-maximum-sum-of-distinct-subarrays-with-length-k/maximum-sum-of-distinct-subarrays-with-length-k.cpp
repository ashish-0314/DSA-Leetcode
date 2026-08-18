class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l = 0;
        long long sum = 0 , maxi = 0 ;
        for(int r = 0 ; r < nums.size() ; r++){
            sum+=nums[r];
            if (mp.count(nums[r]) && mp[nums[r]] >= l) {
                int newL = mp[nums[r]] + 1;
                while (l < newL) {
                    sum -= nums[l];
                    l++;
                }
            }
            mp[nums[r]] = r;
            if(r-l+1==k){
                maxi = max(maxi,sum);
                sum-=nums[l];
                l++;
            }
        }
        return maxi;
    }
};