class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7 ;
        stack<int> st ;
        long long sum = 0 ;
        for(int i = 0 ; i <= n ; i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int idx = st.top();
                st.pop();
                int left = (st.empty()) ? idx+1 : idx-st.top();
                int right = i-idx ;
                sum = (sum + 1LL * arr[idx] * left %MOD * right)%MOD;
            }
            st.push(i);
        }
        return sum;
    }
};