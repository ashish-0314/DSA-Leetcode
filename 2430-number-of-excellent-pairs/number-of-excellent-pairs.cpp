typedef long long ll;
class Solution {
    int BitCount(int x){
        int ans = 0 ;
        for(int j = 29 ; j >=0 ; j--) if((1<<j)&x) ans++;
        return ans;
    }
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> uniq;
        for(auto i: nums) uniq.insert(i);
        vector<int> bits;
        for(auto i: uniq) bits.push_back(BitCount(i));
        sort(bits.begin(),bits.end());
        int n = bits.size();
        int l = 0 , r = n-1;
        ll res = 0;
        while(l<n && r>=0){
            if(bits[l]+bits[r]<k) l++;
            else{
                res+=(n-l);
                r--;
            }
        }
        return res;
    }
};