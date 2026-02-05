class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans = 0;
        for(int x : nums){
            int need = k-x;
            if(m[need]>0) {
                ans++;
                m[need]--;
            }else m[x]++;
        }
        return ans;
    }
};