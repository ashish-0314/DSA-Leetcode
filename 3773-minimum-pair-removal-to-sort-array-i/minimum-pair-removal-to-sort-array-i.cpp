class Solution {
public:
    int minpairidx(vector<int>& nums){
        int minSum = INT_MAX;
        int idx = -1 ;
        for(int i = 0 ; i< nums.size()-1 ; i++){
            if(nums[i]+nums[i+1]<minSum){
                idx = i ;
                minSum = nums[i]+nums[i+1] ;
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0 ;
        while(!is_sorted(begin(nums),end(nums))){
            int idx = minpairidx(nums);
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(begin(nums)+idx+1);
            ops++;
        }
        return ops;
    }
};