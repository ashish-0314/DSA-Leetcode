class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mini = INT_MAX;
        int minIdx = -1;
        int maxi = INT_MIN;
        int maxIdx = -1;
        int n = nums.size();
        if(n-indexDifference<0) return {-1,-1};
        for(int i = 0 ; i < n-indexDifference ; i++){
            if(nums[i]<mini){
                mini = nums[i];
                minIdx = i ;
            }
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIdx = i;
            }
            if(abs(nums[i+indexDifference]-maxi)>=valueDifference) return {maxIdx,i+indexDifference};
            if(abs(nums[i+indexDifference]-mini)>=valueDifference) return {minIdx,i+indexDifference};
        }
        return {-1,-1};
    }
};