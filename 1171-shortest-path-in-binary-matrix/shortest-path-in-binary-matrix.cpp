class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int, pair<int,int>>> q ;
        vector<vector<int>> dist(n , vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;
            if(row==n-1 && col == n-1) return dis;

            for(int i = -1 ; i <=1 ; i++){
                for(int j = -1 ; j <= 1 ; j++){
                    if(i==0 && j== 0) continue;
                    int nr = row + i;
                    int nc = col + j;
                    if(nr>= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc]==0 && dis + 1 < dist[nr][nc]){
                        dist[nr][nc]=dis+1;
                        q.push({dis+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};