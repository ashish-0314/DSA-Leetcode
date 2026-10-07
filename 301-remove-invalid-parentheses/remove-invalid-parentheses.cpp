class Solution {
public:
    unordered_set<string> st;
    void solve(string &s, int idx, int left, int right, int balance, string cur) {
        if (idx == s.size()) {
            if (left == 0 && right == 0 && balance == 0) st.insert(cur);
            return;
        }
        char c = s[idx];
        if (c == '(' && left > 0) solve(s, idx + 1, left - 1, right, balance, cur);
        if (c == ')' && right > 0) solve(s, idx + 1, left, right - 1, balance, cur);
        if (c != '(' && c != ')') solve(s, idx + 1, left, right, balance, cur + c);
        else if (c == '(') solve(s, idx + 1, left, right, balance + 1, cur + c);
        else if (balance > 0) solve(s, idx + 1, left, right, balance - 1, cur + c);
        
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }

        solve(s, 0, left, right, 0, "");
        return vector<string>(st.begin(), st.end());
    }
};