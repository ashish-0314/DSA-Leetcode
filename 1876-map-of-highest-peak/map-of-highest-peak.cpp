class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[r][c]=steps;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int k = 0 ; k < 4 ; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && isWater[nr][nc]==0 && !vis[nr][nc]){
                    q.push({{nr,nc},steps+1});
                    vis[nr][nc]=1;
                }
            }

        }
        return dist;
    }
};