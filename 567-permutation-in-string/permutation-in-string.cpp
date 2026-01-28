class Solution {
public:
    bool allZero(vector<int> & counter){
        for(int i : counter){
            if(i!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> counter(26,0);
        for(int i = 0 ; i< s1.size() ; i++){
            counter[s1[i]-'a']++;
        }
        int i = 0 , j = 0;
        int n = s2.size();
        while(j<n){
            counter[s2[j]-'a']--;
            if(j-i+1==s1.size()){
                if(allZero(counter)) return true;
                counter[s2[i]-'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};