class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(),deadends.end());
        string start = "0000";
        if(st.count(start)) return -1;
        queue<string> q ;
        q.push(start);
        st.insert(start);
        int turn = 0 ;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr==target) return turn;
                for(int i = 0 ; i< 4 ; i++){
                    
                    char ch = curr[i];
                    char dec = ch=='0' ? '9' : ch-1;
                    char inc = ch=='9' ? '0' : ch+1;
                    curr[i]=dec;
                    if(st.find(curr) == st.end()){
                        st.insert(curr);
                        q.push(curr);
                    }
                    curr[i]=inc;
                    if(st.find(curr) == st.end()){
                        st.insert(curr);
                        q.push(curr);
                    }
                    curr[i]=ch;
                }
            }
            turn++;
        }
        return -1;
    }
};