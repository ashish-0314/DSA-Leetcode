class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        queue<string> q ;
        q.push(startGene);
        vector<char> choice= {'A','C','G','T'};
        int mutation = 0 ;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr==endGene) return mutation;
                for(int i = 0 ; i < curr.size() ; i++){
                    char ch = curr[i];
                    for(char &c :  choice){
                        curr[i]=c;
                        if(st.find(curr)!=st.end()){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=ch;
                }
            }
            mutation++;
        }
        return -1;
    }
};