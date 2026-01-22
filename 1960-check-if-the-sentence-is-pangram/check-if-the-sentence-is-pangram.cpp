class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> charcount(26,0);
        for(int i = 0 ; i< sentence.length() ; i++){
            charcount[sentence[i]-'a']++;
        }
        for(int cnt : charcount){
            if(cnt==0) return false;
        }
        return true;
    }
};


