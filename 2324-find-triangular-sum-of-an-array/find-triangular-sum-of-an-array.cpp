class Solution {
public:
    int triangularSum(vector<int>& nums) {
            // vector<int> temp;
            int n = nums.size();
            for(int size = n-1 ; size>=1 ; size--){
                for(int i = 0 ; i < size ; i++){
                // temp.push_back((nums[i]+nums[i+1])%10);
                nums[i] = (nums[i]+nums[i+1])%10;
                }
            }
            // nums = move(temp);
        return nums[0];
    }
};