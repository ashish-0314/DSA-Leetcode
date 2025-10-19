class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> stEnd(n+1,0);
        for(int i = 0 ; i< ranges.size() ; i++){
            int st = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);
            stEnd[st]=max(stEnd[st],end);
        }
        int taps = 0 , maxEnd = 0 , currEnd = 0;
        for(int i = 0 ; i<=n ; i++){
            if(i>maxEnd) return -1;
            if(i>currEnd){
                taps++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd , stEnd[i]);
        }
        return taps;
    }
};