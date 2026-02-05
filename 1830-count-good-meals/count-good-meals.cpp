class Solution {
public:
    int countPairs(vector<int>& d) {
        unordered_map<int,int>m;
        const int mod =1e9 + 7;
        long long ans=0;
        for(int x:d){
            for(int p = 1 ; p<=(1<<21) ; p<<=1){
                int need = p-x;
                if(m.count(need)) ans = (ans+m[need]) % mod;
                
            }
            m[x]++;
        }
        return ans;
    }
};