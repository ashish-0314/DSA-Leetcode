class Solution {
public:
    // int fun(int n){
    //     int sum = 0;
    //     while(n>0){
    //         int digit = n%10;
    //         sum+=(digit*digit);
    //         n/=10;
    //     }
    //     return sum;
    // }
    bool isHappy(int n) {
        // int fst = n , second = fun(n);
        // while(fst != -1 && second!= fst){
        //     fst = fun(n);
        //     second = fun(fun(n));
        // }
        // return fst==1;
        set<int>s;
        while(true){
            int sum=0;
            while(n!=0){
                int digit = n%10;
                sum+=pow(digit,2);
                n/=10;
            }
            if(sum==1){
                return true;
            }
            n=sum;
            if(s.find(n)!=s.end()){
                return false;
            }
            s.insert(n);
        }
    }
};