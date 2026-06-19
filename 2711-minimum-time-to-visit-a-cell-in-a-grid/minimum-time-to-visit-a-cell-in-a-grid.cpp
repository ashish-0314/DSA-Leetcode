class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        priority_queue<pair<int ,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq ;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        pq.push({0,{0,0}});
        dist[0][0] = 0 ;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int time = pq.top().first;
            pq.pop();
            if(vis[row][col]) continue;
            vis[row][col]=true;
            if(row==n-1 && col == m-1) return time;
            for(int k =0 ; k < 4 ; k++){
                int nr = row+dr[k];
                int nc = col + dc[k];
                if(nr<n && nr >=0 && nc < m && nc >=0){
                   if(grid[nr][nc]<= time+1){
                    pq.push({time+1,{nr,nc}});
                    dist[nr][nc]=time+1;
                   } else if((grid[nr][nc]-time)%2==0){
                    pq.push({grid[nr][nc]+1,{nr,nc}});
                    dist[nr][nc]=grid[nr][nc]+1;
                   } else {
                    pq.push({grid[nr][nc],{nr,nc}});
                    dist[nr][nc]= grid[nr][nc];
                   }
                }
            }
        }
        return -1;
    }
};