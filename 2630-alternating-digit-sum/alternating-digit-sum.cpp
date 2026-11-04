class Solution {
public:
    int alternateDigitSum(int n) {
        int sign = 1;
        int ans = 0 ;
        while(n>0){
            ans+=(n%10)*sign;
            n/=10;
            sign *= -1;
        }
        if(sign == 1) return -ans;
        return ans;
    }
};