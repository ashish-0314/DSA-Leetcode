class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0 ;
        for(int i = 0 ; i< s.size() ; i++){
            int distinct = 0 ;
            int maxfreq = 0 ;
            vector<int> freq(26,0);
            for(int j = i ; j < s.size() ; j++){
                if(freq[s[j]-'a']==0) distinct++;
                freq[s[j]-'a']++;
                maxfreq = max(maxfreq,freq[s[j]-'a']);
                if(maxfreq*distinct==j-i+1){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};