class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for(auto & r : matrix){
            for(auto & c : r) nums.push_back(c);
        }
        sort(nums.begin(),nums.end());
        return nums[k-1];
    }
};