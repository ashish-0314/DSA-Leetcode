class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq ;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0],{0,0}});
        int dx[] = {-1,0,1,0} ;
        int dy[] = {0,1,0,-1} ;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int damage = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            if(damage>dist[x][y]) continue;
            if(x==m-1 && y == n-1) break;
            for(int i = 0 ; i < 4 ; i++){
                int nr = x + dx[i];
                int nc = y + dy[i];
                if(nr<0 || nc <0 || nr>= m || nc>=n) continue;
                int newDamage = damage + grid[nr][nc];
                if(newDamage < dist[nr][nc]){
                    dist[nr][nc] = newDamage;
                    pq.push({newDamage,{nr,nc}});
                }
            }
        }
        return dist[m-1][n-1] < health;
    }
};