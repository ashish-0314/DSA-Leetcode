class Solution {
public:

    bool allZero(vector<int> &counter){
        for(int i : counter){
            if(i!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> counter(26,0);
        for(int i = 0 ; i< m ; i++){
            counter[p[i]-'a']++;
        }

        int i = 0 , j = 0;
        vector<int> res;
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1==m){
                if(allZero(counter)) res.push_back(i);
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};