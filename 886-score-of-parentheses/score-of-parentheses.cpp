class Solution {
public:
    int scoreOfParentheses(string s) {
        int bal = 0 , ans = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='(') bal++;
            else{
                bal--;
                if(s[i-1]=='(') ans+=pow(2,bal);
            }
        }
        return ans;
    }
};