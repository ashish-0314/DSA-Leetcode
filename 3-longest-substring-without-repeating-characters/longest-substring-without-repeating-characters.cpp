class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0 , maxLen = 0 ;
       unordered_map<char,int> mp ;
       for(int i = 0 ; i< s.length() ; i++){
        if(mp.find(s[i])!= mp.end() && mp[s[i]]>=l){
            l=mp[s[i]]+1;
        }
        mp[s[i]]=i;
        maxLen = max(maxLen,i-l+1);

       }
       return maxLen;
    }
};