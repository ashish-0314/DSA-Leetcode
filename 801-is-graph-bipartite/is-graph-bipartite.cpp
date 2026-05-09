class Solution {
public:

    bool dfs(int node , vector<vector<int>>& graph , vector<int> &color ){
        for(auto &it : graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                if(!dfs(it,graph,color)) return false;
            } 
            else if(color[it]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i = 0 ; i < graph.size() ; i++){
            // if(color[i]==-1){
            //     queue<int> q;
            //     q.push(i);
            //     color[i]=0;
            //     while(!q.empty()){
            //         int node = q.front();
            //         q.pop();
            //         for(auto & it : graph[node]){
            //             if(color[it]==-1){
            //                 color[it] = !color[node];
            //                 q.push(it);
            //             }
            //             else if(color[it]==color[node]) return false;
            //         }
            //     }
            // }
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};