class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++) if(nums[i]<0) nums[i]*=-1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long a = 0 , b = 0;
        for(int i = 0 ; i < n/2 ; i++) a+= nums[i]*nums[i];
        for(int i = n/2 ; i <n ; i++) b+= nums[i]*nums[i];
        return b-a;
    }
};