class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](vector<int> &a , vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> tail;
        for(auto &x : env){
            int h = x[1];
            auto it = lower_bound(tail.begin(),tail.end(),h);
            if(it==tail.end()) tail.push_back(h);
            else *it = h ;
        }
        return tail.size();
    }
};