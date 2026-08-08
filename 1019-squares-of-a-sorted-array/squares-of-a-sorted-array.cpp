class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ;
        int r = n-1;
        vector<int> ans(n) ;
        int idx = n-1;
        while(l<=r){
            int lsq = nums[l]*nums[l];
            int rsq = nums[r]*nums[r];
            if(rsq>lsq){
                ans[idx]=rsq;
                idx--;
                r--;
            }
            else{
                ans[idx]=lsq;
                idx--;
                l++;
            }
        }
        return ans;
    }
};