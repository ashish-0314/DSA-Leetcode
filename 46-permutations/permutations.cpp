class Solution {
public:
    void generate(vector<int>& curr , vector<int> & nums , vector<vector<int>>& res){
        if(nums.size()==0){
            res.push_back(curr);
            return;
        }
        for(int i = 0 ; i< nums.size() ; i++){
            int x = nums[i];
            curr.push_back(x);
            nums.erase(nums.begin()+i);
            generate(curr,nums,res);
            curr.pop_back();
            nums.insert(nums.begin() +i , x);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        generate(curr,nums,res);
        return res;
    }
};