class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto & r : roads){
            int u = r[0];
            int v = r[1];
            int wt = r[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>>pq;
        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        long long mod = 1e9+7;
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            //if(dis>dist[node]) continue;
            for(auto & it : adj[node]){
                int adjNode = it.first;
                int edWt = it.second;
                if(dis+edWt < dist[adjNode]){
                    dist[adjNode] = dis+edWt;
                    pq.push({dis+edWt,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis+edWt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};