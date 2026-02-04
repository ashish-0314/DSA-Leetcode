class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int num : nums1) mp[num]++;
        for(int x: nums2){
            if(mp.find(x)!= mp.end()){
                res.push_back(x);
                mp.erase(x);
            }
        }
        return res;
    }
};