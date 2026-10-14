class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ele = "";
        while(num--){
            int d = min(9,sum);
            ele+=to_string(d);
            sum-=d;
        }
        return ele;

    }
};