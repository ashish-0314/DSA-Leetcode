class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        int l = 0 ; 
        int r = n-1;
        vector<int> ans ;
        while(l<r){
            int sum = num[l]+num[r];
            if(sum>target) r--;
            else if (sum<target) l++;
            else return {l+1,r+1};
        }
        return {-1,-1};
    }
};