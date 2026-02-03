class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int mindiff = 1e9;
        for(int i= 1 ; i < nums.size() ; i++){
            int diff = nums[i]-nums[i-1];
            mindiff = min(diff,mindiff);
        }
        for(int i = 0 ; i< nums.size()-1 ; i++){
            if(nums[i+1]-nums[i]==mindiff){
                ans.push_back({nums[i],nums[i+1]});
            }
        }

return ans;

    }
};