class Solution {
public:
    bool checkValidString(string s) {
        int hbal = 0 , lbal = 0 ;
        for(char c : s){
            if(c=='('){
                hbal++;
                lbal++;
            } else if (c=='*'){
                hbal++;
                lbal--;
                if(lbal<0) lbal = 0 ;
            } else{
                hbal--;
                lbal--;
                if(lbal<0) lbal = 0 ;
                if(hbal<0) return false;
            }
        }
        return lbal==0;
    }
};