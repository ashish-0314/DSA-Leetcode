class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];
    int solve(int OnesLeft , int ZeroLeft , bool wasLastOne , int limit){
        if(OnesLeft == 0 && ZeroLeft ==0) return 1;
        int result = 0 ;
        if(t[OnesLeft][ZeroLeft][wasLastOne] != -1) return t[OnesLeft][ZeroLeft][wasLastOne];
        if(wasLastOne == true){
            for(int len = 1 ; len <= min(ZeroLeft,limit) ; len++){
                result = (result + solve(OnesLeft , ZeroLeft-len , false , limit)) % M;
            }
        }
        else{
            for(int len = 1 ; len <= min(OnesLeft,limit) ; len++){
                result = (result +solve(OnesLeft-len , ZeroLeft , true , limit))%M;
            }
        }
        return t[OnesLeft][ZeroLeft][wasLastOne] = result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int startWWithOne = solve(one , zero , false , limit);
        int startWWithZero = solve(one , zero , true , limit);
        return (startWWithOne + startWWithZero) % M;
    }
};