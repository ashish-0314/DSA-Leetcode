class Solution {
public:
    typedef pair<int,int> P;  //{finTime , serverId}
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> AvlServer;
        for(int i  = 0 ; i < k ; i++) AvlServer.insert(i);
        priority_queue<P,vector<P> , greater<P>> busyServer;
        vector<int> reqCnt(k,0);
        for(int i = 0 ; i < arrival.size() ; i++){
            int time = arrival[i];
            while(!busyServer.empty() && busyServer.top().first <= time){
                int server = busyServer.top().second;
                busyServer.pop();
                AvlServer.insert(server);
            }
            int target = i%k;
            auto it = AvlServer.lower_bound(target);
            if(it == AvlServer.end()) it=AvlServer.begin();
            if(AvlServer.empty()) continue;
            int targetServer = *it;
            AvlServer.erase(it);
            busyServer.push({(time+load[i]),targetServer});
            reqCnt[targetServer]++;
        }
        vector<int> ans;
        int maxReq = *max_element(reqCnt.begin(),reqCnt.end());
        for(int i = 0 ; i < k ; i++) if(reqCnt[i]==maxReq) ans.push_back(i);
        return ans;
    }
};