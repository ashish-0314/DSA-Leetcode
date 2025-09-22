class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto &ele : nums){
            m[ele]++;
        }

        int maxFreq = 0;
        for(auto &ele : m){
            maxFreq = max(maxFreq,ele.second);
        }
        int sum = 0;
        for(auto &ele : m){
            if(ele.second == maxFreq){
                sum+=ele.second;
            }
        }
        return sum;
    }
};