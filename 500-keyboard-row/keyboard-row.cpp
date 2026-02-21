class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";
        for(char c : r1) mp[c]=1;
        for(char c : r2) mp[c]=2;
        for(char c : r3) mp[c]=3;
        vector<string> res;
        for(string w : words){
            int first = mp[tolower(w[0])];
            bool valid = true;
            for(char c : w){
                if(mp[tolower(c)] != first){
                    valid = false;
                    break;
                }
            }
                if(valid) res.push_back(w);
        }
        return res;
    }
};