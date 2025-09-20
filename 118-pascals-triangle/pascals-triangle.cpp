class Solution {
public:
    vector<int> generaterow(int n){
        vector<int> ansrow;
        ansrow.push_back(1);
        long long ans = 1;
        for(int i =1 ; i< n ; i++){
            ans*=(n-i);
            ans/=i;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1 ; i<=numRows ; i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};