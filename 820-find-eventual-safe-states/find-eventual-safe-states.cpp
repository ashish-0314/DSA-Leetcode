class Solution {
public:

    bool dfs(int node ,vector<vector<int>>& graph , vector<int> & vis , vector<int> & Pathvis , vector<int> &check ){
        vis[node]=1;
        Pathvis[node]=1;
        check[node]=0;
        for(auto & it : graph[node]){
            if(!vis[it]) {
                if(dfs(it,graph,vis,Pathvis,check)) return true;
            }
            else if(Pathvis[it]) return true;
        }
        check[node]=1;
        Pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> Pathvis(n,0);
        vector<int> check(n,0);
        vector<int> safe;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) dfs(i,graph,vis,Pathvis,check);
        }
        for(int i = 0 ; i < n ; i++){
            if(check[i]==1) safe.push_back(i);
        }
        return safe;
    }
};