class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) { 
        vector<int> freq(50, 0);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) freq[nums[i] + 50]++;
            if(i >= k) {
                if(nums[i - k] < 0) freq[nums[i - k] + 50]--;
            }
            if(i >= k - 1) {
                int cnt = 0;
                int beauty = 0;
                for(int val = -50; val <= -1; val++) {
                    cnt += freq[val + 50];
                    if(cnt >= x) {
                        beauty = val;
                        break;
                    }
                }
                ans.push_back(beauty);
            }
        }
        return ans;
    }
};