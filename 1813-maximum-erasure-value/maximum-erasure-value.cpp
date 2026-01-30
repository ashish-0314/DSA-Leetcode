class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
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

            maxi = max(maxi,sum);
        }
        return maxi;
    }
};