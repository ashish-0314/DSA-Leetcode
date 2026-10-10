class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> cntdiff(1e5+1,0);
        for(int i = 0 ; i < n ; i++){
            int d = abs(nums1[i]-nums2[i]);
            cntdiff[d]++;
        }
        int k = k1+k2;
        for(int i = 1e5 ; i >0 && k>0 ; i--){
            int ops = min(cntdiff[i],k);
            cntdiff[i] -= ops;
            cntdiff[i-1] += ops;
            k-=ops;
        }
        long long res = 0;
        for(long long d = 1; d <=1e5 ; d++){
            res+= (cntdiff[d]*d*d);
        }
        return res;
    }
};