class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxD , minD ;
        long long ans = 0 ;
        int left = 0 ;

        for(int right = 0 ; right < nums.size() ; right++){
            while(!maxD.empty() && nums[maxD.back()] < nums[right]) maxD.pop_back();
            maxD.push_back(right);
            while(!minD.empty() && nums[minD.back()] > nums[right]) minD.pop_back();
            minD.push_back(right);
            while(nums[maxD.front()]- nums[minD.front()]>2){
                if(maxD.front()==left) maxD.pop_front();
                if(minD.front()==left) minD.pop_front();
                left++;
            }
            ans+= (right-left+1);
        }
        return ans;
    }
};