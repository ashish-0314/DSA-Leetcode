class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int &num : nums) if(num<0) num*=-1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0 , r = n-1;
        long long res = 0 ;
        while(l<r){
            res += 1LL * (nums[r]*nums[r] - nums[l]*nums[l]);
            l++;
            r--;
        }
        if (l == r) res += 1LL * nums[l] * nums[l];
        return res;
    }
};