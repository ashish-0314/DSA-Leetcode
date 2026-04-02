class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_idx(n);
        for(int i = 0 ; i < n ; i++) actual_idx[i]=i;
        auto lambda = [&](int &i , int &j){
            return positions[i] < positions[j];
        };
        sort(actual_idx.begin(),actual_idx.end(),lambda);
        vector<int> res;
        stack<int> st;
        for(int &a : actual_idx){
            if(directions[a]=='R') st.push(a);
            else{
                while(!st.empty() && healths[a]>0){
                    int top = st.top();
                    st.pop();
                    if(healths[top]>healths[a]){
                        healths[top]-=1;
                        healths[a]=0;
                        st.push(top);
                    }
                    else if(healths[top]<healths[a]){
                        healths[a]-=1;
                        healths[top]=0;
                    }
                    else{
                        healths[a]=0;
                        healths[top]=0;
                    }
                }
            }
        }
        for(int i = 0 ; i < n ;i++){
            if(healths[i]>0) res.push_back(healths[i]);
        }
        return res;
    }
};