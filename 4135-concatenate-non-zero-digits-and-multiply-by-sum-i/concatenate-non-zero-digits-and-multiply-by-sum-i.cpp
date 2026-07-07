class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0 ;
        long long num = 0 ;
        while(n>0){
            int d = n%10;
            n/=10;
            if(d==0) continue;
            num = num*10 + d;
            sum+=d;
        }
        long long rev = 0 ;
        while(num>0){
            rev = rev * 10 + (num%10);
            num/=10;
        }
        return rev*sum;
    }
};