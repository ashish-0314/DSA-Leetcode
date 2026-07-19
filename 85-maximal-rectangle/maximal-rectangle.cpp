class Solution {
public:

    int solve(vector<int>& heights) {
        int n = heights.size();
        stack<int> st ;
        long long maxi  = 0 ;
        for(int i = 0; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int idx = st.top();
                st.pop();
                int nse = i ;
                int pse = (st.empty()) ? -1 : st.top();
                maxi = max(maxi , 1LL * heights[idx]* (nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            int nse = n ;
            int pse = (st.empty()) ? -1 : st.top();
            maxi = max(maxi , 1LL * heights[idx]* (nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix.empty()) return 0 ;
        vector<vector<int>> pSum(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j]=='1') pSum[i][j] = (i==0) ? 1 : pSum[i-1][j]+1;
                else pSum[i][j]=0;
            }
        }
        long long maxi = 0 ;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi,1LL*solve(pSum[i]));
        }
        return maxi;
    }
};