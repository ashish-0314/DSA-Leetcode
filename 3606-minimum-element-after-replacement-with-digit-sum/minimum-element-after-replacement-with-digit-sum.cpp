class Solution {
public:
    int sumi(int n){
        int sum = 0 ;
        while(n>0){
            sum+= n%10;
            n/=10;
        }
        return sum;
    }
    int ans = 1e9;
    int minElement(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            int a = sumi(nums[i]);
            ans = min(ans,a);
        }
        return ans;
    }
};