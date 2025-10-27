class Solution {
public:
    int countOne(string ele){
        int cnt = 0;
        for(auto &i : ele){
            if(i=='1') cnt++;
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
       int total = 0 , prev = 0;
       for(auto &row : bank){
        int one = countOne(row);
        if(one>0){
            total += one*prev;
            prev= one;
        }
       } 
       return total;
    }
};