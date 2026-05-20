class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<double,int>> pq ;
        vector<double> dist(n,0.0);
        dist[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double probi = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == end_node) return probi;
            for(auto & it : adj[node]){
                int adjNode = it.first;
                double edgeprobi = it.second;
                double newProbi = probi * edgeprobi;
                if(newProbi > dist[adjNode]){
                    dist[adjNode] = newProbi;
                    pq.push({newProbi , adjNode});
                }
            }
        }
        return 0.0;
    }
};