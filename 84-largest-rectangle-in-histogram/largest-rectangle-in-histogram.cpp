class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st ;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        vector<int> nse(n);
        stack<int> st2;
        for(int i = n-1 ; i >=0 ; i--){
            while(!st2.empty() && heights[st2.top()] >= heights[i]) st2.pop();
            nse[i]= (st2.empty()) ? n : st2.top();
            st2.push(i);
        }
        long long maxi = 0 ;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi, 1LL * heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi ;
    }
};