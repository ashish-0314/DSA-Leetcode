class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int,int>> fu(26,{0,-1});
        vector<pair<int,int>> fl(26,{0,-1});
        for(int i = 0 ; i < word.size() ; i++){
            if(word[i]>='a' && word[i]<='z'){
                fl[word[i]-'a'].first++;
                fl[word[i]-'a'].second = i ;
            }
            else{
                fu[word[i]-'A'].first++;
                if(fu[word[i]-'A'].second==-1) fu[word[i]-'A'].second=i;
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if(fu[i].first>0 && fl[i].first>0 && fu[i].second>fl[i].second) cnt++;
        }
        return cnt;
    }
};