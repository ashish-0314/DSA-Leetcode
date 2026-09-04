class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n) ;
        vector<int> mini(n) ;
        int maxn = -1;
        int minn = 1e9;
        for(int i = 0 ; i < n ; i++){
            maxn = max(maxn,nums[i]);
            maxi[i]=maxn;
        }
        for(int i = n-1 ; i>=0 ; i--){
            minn = min(minn , nums[i]);
            mini[i]=minn;
        }
        
        for(int i = 0 ; i < n ; i++){
            int diff = maxi[i]-mini[i];
            if(diff<=k) return i;
            
        }
        return -1;
    }
};