class Solution {
public:
    int m , n ;
    bool dfs(vector<vector<int>>& grid , int r , int c){
        if(r>=m || r <0 || c >=n || c<0) return false;
        if(grid[r][c]==1) return true;
        grid[r][c]=1;
        bool lc = dfs(grid,r,c-1);
        bool rc = dfs(grid,r,c+1);
        bool uc = dfs(grid,r-1,c);
        bool dc = dfs(grid,r+1,c);
        return lc&&rc&&uc&&dc;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n ; j++){
                if(grid[i][j]==0) if(dfs(grid,i,j)) cnt++;
            }
        }
        return cnt;
    }
};