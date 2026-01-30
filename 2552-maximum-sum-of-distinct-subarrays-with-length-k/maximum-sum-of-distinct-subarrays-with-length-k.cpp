class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l = 0;
        long long sum = 0 , maxi = 0 ;
        for(int r = 0 ; r < nums.size() ; r++){
            mp[nums[r]]++;
            sum+=nums[r];

            while(mp[nums[r]]>1){
                mp[nums[l]]--;
                sum-=nums[l];
                l++;
            }

            if(r-l+1==k){
                maxi = max(maxi,sum);
                mp[nums[l]]--;
                sum-=nums[l];
                l++;
            }
        }
        return maxi;
    }
};