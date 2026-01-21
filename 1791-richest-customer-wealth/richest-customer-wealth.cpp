class Solution {
public:
    vector<int> preSum;

    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        // vector<int> preSum;
        int maxi = 0 ;
        for(int i = 0 ; i< n ; i++ ){
            int sum = 0;
            for(int j = 0 ; j< m ; j++){
                sum += accounts[i][j];
            }
            // preSum.push_back(sum);
            maxi = max(sum,maxi);
        }
        //int maxi = *max_element(preSum.begin(),preSum.end());
        return maxi;
    }
};