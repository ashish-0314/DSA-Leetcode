class Solution {
public:
    int maxProduct(int n) {
        int fst = 0;
        int snd = 0;
        while(n>0){
            int d = n%10;
            if(d>fst){
                snd = fst ;
                fst = d;
            } else if(snd < d ) snd = d;
            n/=10;
        }
        return fst*snd;
    }
};