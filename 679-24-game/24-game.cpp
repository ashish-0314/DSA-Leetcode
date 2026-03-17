class Solution {
public:
    bool solve(vector<double>& cards){
        if(cards.size()==1) return abs(cards[0]-24) <= 0.1;
        for(int i = 0 ; i<cards.size() ; i++){
            for(int j = 0 ; j < cards.size() ; j++){
                if(i==j) continue;
                vector<double> temp;
                for(int k = 0 ; k <cards.size() ; k++){
                    if(k!=i && k!=j) temp.push_back(cards[k]);
                }
                double a = cards[i];
                double b = cards[j];
                vector<double> possVal = {a+b , a-b , a*b};
                if(abs(b)>0) possVal.push_back(a/b);
                for(double val : possVal){
                    temp.push_back(val);
                    if(solve(temp)==true) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int x : cards) nums.push_back(1.0*x);
        return solve(nums);
    }
};