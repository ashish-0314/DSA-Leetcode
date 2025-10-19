class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt = 0 , prev = -1e9 ;
        for(int i = 0 ; i< nums.size() ; i++){
            int minVal = nums[i]-k;
            if(prev < minVal){
                prev = nums[i]-k;
                cnt++;
            }
            else if(prev < nums[i]+k){
                prev++;
                cnt++;
            }
        }
        return cnt;
    }
};