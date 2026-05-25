class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // int ans = 0 ;
        // int l =0 ;
        // int r = nums.size()-1;
        // while(l<r){
        //     // int ramp = nums[r]-nums[l];
        //     // ans = max(ans,ramp);
        //     // if(nums[l]>nums[r]) l++;
        //     // else r--;
        //     if(nums[l]>nums[r]) l++;
        //     int ramp = 
        // }
        // return ans;
        int n = nums.size();
        stack<int> st ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(st.empty() || nums[i] < nums[st.top()]) st.push(i);
        }
        int ans = 0 ;
        for(int j =n-1 ; j >= 0 ; j-- ){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                ans = max(ans,j - st.top());
                st.pop();
            }
        }
        return ans;
    }
};