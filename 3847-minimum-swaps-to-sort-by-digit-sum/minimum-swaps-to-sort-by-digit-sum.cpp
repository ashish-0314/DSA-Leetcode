class Solution {
public:
    int dSum(int n){
        int ds = 0 ;
        while(n>0){
            ds += n%10;
            n/=10;
        }
        return ds;
    }
    int minSwaps(vector<int>& nums) {
        int ans = 0 ;
        unordered_map<int,int> mp;
        vector<int> afterSort(nums);
        for(int i = 0 ; i < nums.size(); i++) mp[nums[i]]=i;
        sort(afterSort.begin(),afterSort.end(),[this](int a , int b){
            int ds1 = dSum(a);
            int ds2 = dSum(b);
            if(ds1!=ds2) return ds1<ds2;
            return a<b;
        });
        for(int i = 0 ; i < nums.size() ; i++){
            int expVal = afterSort[i];
            int currVal = nums[i];
            if(expVal == currVal) continue;
            int idx = mp[expVal];
            nums[i]=expVal;
            nums[idx]=currVal;
            mp[expVal]=i;
            mp[currVal]=idx;
            ans++;
        }

        return ans;
    }
};