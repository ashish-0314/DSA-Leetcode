class Solution {
public:
    int bitwiseComplement(int n) {
        int cnt = 0 ;
        int ans = 0 ;
        if(n==0) return 1;
        while(n){
            int r = n%2;
            int x = !r * pow(2,cnt);
            cnt++;
            ans+=x;
            n/=2;
        }
        return ans;
    }
};