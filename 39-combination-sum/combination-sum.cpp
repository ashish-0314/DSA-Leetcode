class Solution {
public:
    void fun(vector<int> & curr , vector<int> & candidates , int target , vector<vector<int>> & res, int start){
        if(target<0) return;
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int i = start ; i< candidates.size() ; i++){
            curr.push_back(candidates[i]);
            fun(curr,candidates,target-candidates[i],res,i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        fun(curr, candidates, target, res,0);
        return res;
    }
};