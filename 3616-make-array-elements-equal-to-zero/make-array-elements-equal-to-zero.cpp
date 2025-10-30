class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int tSum = accumulate(nums.begin(),nums.end(),0);
        int curr = 0 ;
        int ans = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            curr+=nums[i];
            int l= curr;
            int r = tSum-curr;
            if(nums[i]!=0) continue;
            if(l==r) ans+=2;
            if(abs(l-r)==1) ans+=1;

        }
        return ans;
    }
};