class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        //vector<int> ballColour(limit+1,-1);
        unordered_map<int,int> ballColour;
        vector<int> res;
        for(int i = 0 ; i < queries.size() ; i++){
            int ball = queries[i][0];
            int colour = queries[i][1];

            if(ballColour.find(ball) != ballColour.end()){
                int prevC = ballColour[ball];
                mp[prevC]--;
                if(mp[prevC]==0) mp.erase(prevC);
            }

            ballColour[ball] = colour;
            mp[colour]++;
            res.push_back(mp.size());
        }
        return res;
    }
};