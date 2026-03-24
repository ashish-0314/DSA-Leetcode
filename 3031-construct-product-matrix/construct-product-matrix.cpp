class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int s = n*m;
        vector<int> nums;
        nums.reserve(s);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                nums.push_back(grid[i][j]);
            }
        }
        vector<long long> ans(s);
        int mod = 12345;
        ans[0]=1;
        for(int i = 1 ; i< s ; i++){
            ans[i]=(ans[i-1] * nums[i-1])%mod;
        }
        long long r_mult = 1 ;
        for(int i = s-1 ; i >=0 ; i--){
            ans[i]=(ans[i]* r_mult)%mod;
            r_mult = (r_mult*nums[i])%mod; 
        }
        for(int i = 0; i < s; i++) {
            int row = i / m;
            int col = i % m;
            grid[row][col] = ans[i];
        }

    return grid;

    }
};