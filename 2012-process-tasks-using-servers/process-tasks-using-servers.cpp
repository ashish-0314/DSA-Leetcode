class Solution {
public:
    typedef pair<int,int> P;
    typedef tuple<long,int,int> T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P , vector<P> , greater<P>> freeServer;
        priority_queue<T , vector<T> , greater<T>> busyServer;

        for(int i = 0 ; i < n ; i++) freeServer.push({servers[i],i});
        vector<int> res(m);

        for(int i = 0;i < m ; i++){
            while(!busyServer.empty() && get<0>(busyServer.top()) <= i){
                auto[finTime , wt , idx] = busyServer.top();
                busyServer.pop();
                freeServer.push({wt,idx});
            }
            if(freeServer.empty()){
                auto[finTime , wt , idx] = busyServer.top();
                busyServer.pop();
                res[i] = idx;
                busyServer.push({finTime+ tasks[i] , wt , idx});
            } 
            else{
                auto[wt,idx] = freeServer.top();
                freeServer.pop();
                res[i]=idx;
                busyServer.push({i+tasks[i],wt,idx});
            }
        }
        return res;
    }
};