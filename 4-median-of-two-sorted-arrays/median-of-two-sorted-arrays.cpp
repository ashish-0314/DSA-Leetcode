class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size() ;
        vector<int> ans(size);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
        if (size % 2 == 0) return (ans[size/2 - 1] +ans[size/2]) / 2.0;
        else return ans[size/2];
    }
};