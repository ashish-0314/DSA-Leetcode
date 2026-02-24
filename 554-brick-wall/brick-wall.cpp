class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long ,int> mp;
        for(auto &w : wall){
            long long sum = 0 ;
            for(int i = 0 ; i< w.size()-1 ; i++){
                sum += w[i];
                mp[sum]++;
            }
        }
        int maxi = 0 ;
        for(auto &[it , cnt] : mp){
            maxi = max(cnt , maxi);
        }
        return wall.size()-maxi;
    }
};