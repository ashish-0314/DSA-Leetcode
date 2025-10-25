class Solution {
public:
    int totalMoney(int n) {
        int mon_money = 1;
        int ans = 0;
        while(n>0){
            int money = mon_money;
            
            for(int i = 1 ; i<= min(n,7) ; i++){
                ans+=money;
                money++;
            }
            n-=7;
            mon_money++;
        }
        return ans;
    }
};