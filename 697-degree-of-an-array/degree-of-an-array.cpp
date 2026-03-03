class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int,int> freq , fst , last ;
        int deg = 0 ;
        for(int i = 0 ;i < nums.size() ; i++){
            if(fst.find(nums[i]) == fst.end()) fst[nums[i]] = i ;
            last[nums[i]] = i ;
            freq[nums[i]]++;
            deg = max(deg, freq[nums[i]]);
        }
        int ans = 1e9 ;
        for(auto & it : freq){
           if(it.second==deg){
            ans = min(ans ,last[it.first] - fst[it.first] +1 );
           } 
        }
        return ans;
    }
};