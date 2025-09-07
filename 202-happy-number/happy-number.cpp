class Solution {
public:
    int fun(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum+=(digit*digit);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fst = n , second = fun(n);
        while( second != fst){
            fst = fun(fst);
            second = fun(fun(second));
        }
        return fst==1;
       
    }
};