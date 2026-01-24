class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for(int i = 0 ; i< nums.size() ; i++){
        //     mp[nums[i]]++;
        // }
        // int cnt= 0;
        // for(auto &num : mp){
        //     cnt += num.second * ( num.second-1)/2;
        // }
        // return cnt;
        int cnt = 0 ;
        for(int i = 0 ; i< nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i]==nums[j]) cnt++;
            }
        }
        return cnt;
    }
};