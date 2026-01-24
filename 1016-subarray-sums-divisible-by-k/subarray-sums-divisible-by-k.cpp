class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0 , cnt = 0;
        mp[0]=1;
        for(int num : nums){
            sum+=num;
            int rem = sum %k;
            if(rem<0) rem+=k;
            cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
    }
};