class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> f(nums.size(),1);
        vector<int> b(nums.size(),1);

        for(int i = 1 ; i< nums.size() ; i++){
            if(nums[i]<=nums[i-1]) f[i]=f[i-1]+1;
        }

        for(int i = nums.size()-2 ; i>=0 ; i--){
            if(nums[i]<=nums[i+1]) b[i]=b[i+1]+1;
        }

        vector<int> ans;
        for(int i = k ; i< nums.size()-k ; i++){
            if(f[i-1]>=k && b[i+1]>=k) ans.push_back(i);
        }
        return ans;
    }
};