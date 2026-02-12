class Solution {
public:
    int allequal(vector<int>& freq){
        int same = 0;
        for(int i = 0 ; i< 26 ; i++){
            if(freq[i]==0) continue;
            if(same==0) same = freq[i];
            else if(freq[i] != same) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int maxL = 0 ;
        for(int i = 0 ; i< s.size() ; i++){
            vector<int> freq(26,0);
            for(int j = i ; j < s.size() ; j++){
                freq[s[j]-'a']++;
                if(allequal(freq)){
                    maxL = max(maxL , j-i+1);
                }
            }
        }
        return maxL;
    }
};