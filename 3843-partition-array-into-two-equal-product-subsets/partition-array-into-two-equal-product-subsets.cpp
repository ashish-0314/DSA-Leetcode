class Solution {
public:
    bool solve(int idx , long long p1 , long long p2, long long target ,vector<int>& nums ){
        if(idx == nums.size()) return p1==target && p2==target;
        if(p1>target || p2>target) return false;
        bool a = solve(idx+1,p1*nums[idx],p2,target,nums);
        bool b = solve(idx+1,p1,p2*nums[idx],target,nums);
        return a||b;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(0,1,1,target,nums);
    }
};