class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int s = n*m;
        vector<long long> ans(s);
        int mod = 12345;
        ans[0]=1;
        for(int i = 1 ; i < s ; i++){
            int val = grid[(i-1)/m][(i-1)%m];
            ans[i] = (ans[i-1]*val)%mod;
        }
        long long r_mult = 1 ;
        for(int i = s-1 ; i >=0 ; i--){
           ans[i] = (ans[i]*r_mult)%mod;
           int val = grid[i/m][i%m];
           r_mult = (r_mult*val)%mod; 
        }
        for(int i = 0; i < s; i++) {
            int row = i / m;
            int col = i % m;
            grid[row][col] = ans[i];
        }

    return grid;

    }
};