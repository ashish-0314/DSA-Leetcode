class Solution {
public:

    int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int area = 1;
        for(int k = 0 ; k < 4 ; k++){
            int nr = i + delrow[k];
            int nc = j + delcol[k];
            if(nr>=0 && nr < n && nc >=0 && nc < m && grid[nr][nc]==1 && !vis[nr][nc]){
                area+=dfs(nr,nc,grid,vis);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int> (m,0));
        int maxi = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area = dfs(i,j,grid,vis);
                    maxi = max(maxi ,area);
                }
            }
        }
        return maxi;
    }
};