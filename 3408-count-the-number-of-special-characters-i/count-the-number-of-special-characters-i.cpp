class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> fu(26,0);
        vector<int> fl(26,0);
        for(char c : word){
            if(c>='a' && c <='z') fl[c-'a']++;
            else fu[c-'A']++;
        }
        int cnt = 0 ;
        for(int i = 0 ; i < 26 ; i++) if(fu[i]>0 && fl[i]>0) cnt++;
        return cnt;
    }
};