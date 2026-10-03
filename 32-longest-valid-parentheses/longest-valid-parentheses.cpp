class Solution {
public:
    int longestValidParentheses(string s) {
        int bal = 0 , curr = 0 , ans = 0 ;
        for(char c : s){
            if(c=='(') bal++;
            else bal--;
            curr++;
            if(bal<0){
                bal=0;
                curr=0;
            }else if(bal==0) ans = max(ans,curr);
        }
        bal = 0 , curr= 0 ;
        for(int i = s.size()-1 ; i>=0 ; i--){
            char c = s[i];
            if(c==')') bal++;
            else bal--;
            curr++;
            if(bal<0){
                bal=0;
                curr=0;
            }else if(bal==0) ans = max(ans,curr);
        }
        return ans;
    }
};