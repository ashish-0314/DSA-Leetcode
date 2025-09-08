class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> charcnt(26,0);
       if(s.length() != t.length()) return false;
       for(int i = 0 ; i< s.length() ; i++){
        charcnt[s[i] - 'a']++;
        charcnt[t[i]-'a']--;
       }
       for(int &count : charcnt){
        if(count != 0) return false;
       } 
       return true;
    }
};