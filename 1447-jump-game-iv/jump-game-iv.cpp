class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp ;
        vector<bool> vis(n,false);
        for(int i = 0 ; i < n ; i++) mp[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int steps = 0 ;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();
                int l = curr-1;
                int r = curr+1;
                if(curr==n-1) return steps;
                if(l>=0 && !vis[l]){
                    q.push(l);
                    vis[l]=true;
                }
                if(r<n && !vis[r]){
                    q.push(r);
                    vis[r]=true;
                }
                for(auto & idx: mp[arr[curr]]){
                    if(!vis[idx]){
                        q.push(idx);
                        vis[idx]=true;
                    } 
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return steps;
    }
};