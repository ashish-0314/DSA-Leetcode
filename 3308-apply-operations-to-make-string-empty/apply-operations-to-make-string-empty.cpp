class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> freq;
        int maxfreq = 0 ;
        for(int i = 0 ; i< s.length() ; i++){
            freq[s[i]]++;
            maxfreq = max(maxfreq,freq[s[i]]);
        }
        unordered_map<char,int> currfreq;
        string ans = "";
        for(int i = 0 ; i< s.length() ; i++){
            currfreq[s[i]]++;
            if(currfreq[s[i]]==maxfreq) ans.push_back(s[i]);
        }
        return ans;
    }
};