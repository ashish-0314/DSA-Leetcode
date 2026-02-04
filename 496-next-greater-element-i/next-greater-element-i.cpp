class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp ;
        for(int i = 0 ; i< nums2.size() ; i++) mp[nums2[i]]=i;
        vector<int> res;
        for(int i = 0 ; i< nums1.size() ; i++){
            int idx = mp[nums1[i]];
            int nxt = -1;
            for(int j = idx+1 ; j < nums2.size() ; j++){
                if(nums2[j]>nums1[i]){
                    nxt = nums2[j];
                    break;
                }
            }
            res.push_back(nxt);
        }
        return res;
    }
};