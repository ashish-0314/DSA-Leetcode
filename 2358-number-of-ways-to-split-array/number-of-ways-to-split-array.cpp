class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       long long sum = accumulate(nums.begin(),nums.end(),0LL);
       long long lsum = 0 ;
       int cnt = 0;
       for(int i = 0 ; i < nums.size()-1 ; i++){
        lsum+=nums[i];
        long long rsum = sum - lsum ;
        if(lsum>=rsum) cnt++;
       } 
       return cnt;
    }
};