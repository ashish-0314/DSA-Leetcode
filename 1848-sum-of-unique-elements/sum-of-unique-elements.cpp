class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(int num : nums) mp[num]++;
       int cnt = 0 ;
       for(auto &it : mp){
        if(it.second==1) cnt+=it.first;
       } 
       return cnt;
    }
};