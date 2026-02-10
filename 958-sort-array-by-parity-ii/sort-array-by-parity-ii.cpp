class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int eveni = 0 , oddi = 1;
        while(eveni < n && oddi < n){
            if(nums[eveni]%2==0) eveni+=2;
            else if(nums[oddi]%2==1) oddi+=2;
            else {
                swap(nums[eveni],nums[oddi]);
                eveni+=2;
                oddi+=2;
            }
        }
        return nums;
    }
};