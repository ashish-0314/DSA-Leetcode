class Solution {
public:
    int m , n ;
    int t[501][501][3];
    int solve(vector<vector<int>>& coins , int i , int j , int ne){
        if(i==m-1 && j == n-1){
            if(coins[i][j]<0 && ne >0) return 0;
            return coins[i][j];
        }
        if(i>=m || j>= n) return INT_MIN;
        if(t[i][j][ne] != INT_MIN) return t[i][j][ne];
        int take = coins[i][j] + max(solve(coins,i+1,j,ne) , solve(coins,i,j+1,ne));
        int skip = INT_MIN;
        if(coins[i][j]<0 && ne >0){
            int skipR = solve(coins,i,j+1,ne-1);
            int skipD = solve(coins,i+1, j , ne-1);
            skip = max(skipR,skipD);
        }
        return t[i][j][ne] = max(take,skip);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins,0,0,2);
    }
};