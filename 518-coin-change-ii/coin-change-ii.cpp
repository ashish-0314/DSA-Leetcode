class Solution {
public:
    // int fun(int idx , int amount , vector<int>& coins , vector<vector<int>> & dp){
    //     if(idx == 0){
    //         if(amount % coins[0] == 0) return 1;
    //         return 0;
    //     }
    //     if(dp[idx][amount] != -1) return dp[idx][amount];
    //     int notTake = 0 + fun(idx-1,amount,coins,dp);
    //     int Take = 0;
    //     if(coins[idx]<=amount) Take =fun(idx,amount-coins[idx],coins,dp);
    //     return dp[idx][amount] = Take + notTake ;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        // return fun(n-1,amount,coins,dp);
        // vector<vector<int>> dp(n, vector<int> (amount+1,0));
        vector<int> prev(amount+1 , 0) , curr(amount+1 , 0);
        for(int i = 0 ; i<= amount ; i++){
            if(i % coins[0]==0) prev[i] = 1;
        }
        for(int i = 1 ; i< n ; i++){
            for(int j = 0 ; j<= amount ; j++){
                long long notTake = prev[j];
                long long Take = 0 ;
                if(coins[i] <= j) Take = curr[j- coins[i]];
                curr[j] = Take + notTake;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};