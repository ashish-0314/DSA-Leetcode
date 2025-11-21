class Solution {
public:
    void generate(int idx, vector<int> & curr ,vector<int> & nums ,vector<vector<int>> & res){
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
            generate(idx+1, curr , nums, res);
            curr.push_back(nums[idx]);
            generate(idx+1, curr , nums, res);
            curr.pop_back();
        }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        generate(0,curr,nums,res);
        return res;
    }
};