class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;
        if(k==nums.size()) return *max_element(nums.begin(),nums.end());
        for(int i = 0 ; i <= nums.size()-k ; i++){
            for(int j = i ; j <= i+k-1 ; j++) mp[nums[j]]++;
        }
        int maxi = INT_MIN;
        for(auto & it : mp){
            if(it.second == 1) maxi = max(maxi,it.first);
        }
        return (maxi==INT_MIN) ? -1 : maxi;

    }
};