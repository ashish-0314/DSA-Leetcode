class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;
        for(auto &ele : operations){
            if(ele=="++X" || ele == "X++") cnt++;
            else cnt--;
        }
        return cnt;
        
    }
};