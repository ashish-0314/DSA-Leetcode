class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n = word.size();
        string ans = "";
        int len = n-numFriends+1;
        for(int i = 0 ; i < n ; i++){
            string curr = word.substr(i,min(len,n-i));
            ans = max(ans,curr);
        }
        return ans;
    }
};