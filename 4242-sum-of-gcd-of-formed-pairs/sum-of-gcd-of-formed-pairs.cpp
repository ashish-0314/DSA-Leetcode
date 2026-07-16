class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> maxi;
        maxi.push_back(nums[0]);
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]>=maxi[i-1]) maxi.push_back(nums[i]);
            else maxi.push_back(maxi[i-1]);
        }
        vector<int> pGcd;
        for(int i = 0 ; i < nums.size();i++){
            pGcd.push_back(gcd(nums[i],maxi[i]));
        }
        sort(pGcd.begin(),pGcd.end());
        long long sum = 0 ;
        int l = 0 , r = nums.size()-1;
        while(l<r){
            sum+=gcd(pGcd[l++],pGcd[r--]);
        }
        return sum ;
    }
};