class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto & row: grid){
            for(auto &val : row) nums.push_back(val);
        }
        int r = nums[0]%x;
        for(int i = 1 ; i < nums.size() ; i++){
            if(r != nums[i]%x) return -1;
        }
        sort(nums.begin(),nums.end());
        int t = nums[nums.size()/2];
        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            ans += abs(nums[i]-t)/x;
        }
        return ans;
    }
};