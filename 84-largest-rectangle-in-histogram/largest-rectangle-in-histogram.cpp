class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st ;
        long long maxi  = 0 ;
        for(int i = 0; i < n ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
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
};