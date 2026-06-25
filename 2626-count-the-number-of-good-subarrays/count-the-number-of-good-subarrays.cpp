class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long> freq;
        long long pairs = 0 ;
        long long ans =  0 ;
        int left = 0 ;
        int n = nums.size();
        for(int j = 0 ; j < n ; j++){
            pairs+= freq[nums[j]];
            freq[nums[j]]++;
            while(pairs>=k){
                ans += n-j;
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }
        return ans ;
    }
};