class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& src) {
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        vector<vector<int>> grid(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(auto & s : src){
            int r = s[0];
            int c = s[1];
            int color = s[2];
            grid[r][c]=color;
            dist[r][c]=0;
            q.push({{r,c},color});

        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int color = q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int k = 0 ; k < 4 ; k++){
                int nr = r + delrow[k];
                int nc = c + delcol[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(dist[nr][nc]> dist[r][c]+1){
                        dist[nr][nc]= dist[r][c]+1;
                        grid[nr][nc]=color;
                        q.push({{nr,nc},color});
                    }
                    else if(dist[nr][nc]==dist[r][c]+1){
                        if(color > grid[nr][nc]){
                            grid[nr][nc] = color;
                            q.push({{nr,nc}, color});
                        }
                    }
                }
            }

        }
        return grid;
    }
};