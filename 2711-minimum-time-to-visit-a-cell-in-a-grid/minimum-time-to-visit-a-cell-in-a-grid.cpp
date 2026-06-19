class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int r = pos.first;
            int c = pos.second;
            if (time > dist[r][c]) continue;
            if (r == n - 1 && c == m - 1) return time;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int nt;
                if (grid[nr][nc] <= time + 1) nt = time + 1;
                else {
                    if ((grid[nr][nc] - time) % 2 == 0)
                        nt = grid[nr][nc] + 1;
                    else
                        nt = grid[nr][nc];
                }
                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    pq.push({nt, {nr, nc}});
                }
            }
        }

        return -1;
    }
};