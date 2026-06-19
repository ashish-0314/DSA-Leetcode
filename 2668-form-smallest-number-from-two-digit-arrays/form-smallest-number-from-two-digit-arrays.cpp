class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int minElement1 = *min_element(nums1.begin(),nums1.end());
        int minElement2 = *min_element(nums2.begin(),nums2.end());
        //if(minElement1 == minElement2) return minElement1;
        unordered_set<int> s(nums1.begin(),nums1.end());
        int common = 10;
        for(int x : nums2){
            if(s.count(x)) common = min(common,x);
        }
        if(common!=10) return common;

        else return min(minElement1,minElement2)*10 + max(minElement1,minElement2);
    }
};