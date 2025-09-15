class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brooky(brokenLetters.begin(), brokenLetters.end());
        int cnt = 0;
        bool canType = true;
        for(char c : text){
            if(c==' '){
                if(canType) cnt++;
                canType = true;
            }
            else if(brooky.count(c)) canType = false;
        }
        if(canType) cnt++;
        return cnt;
    }
};