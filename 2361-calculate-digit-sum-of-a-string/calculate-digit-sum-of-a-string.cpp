class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            string temp = "";
            for(int i = 0 ; i < s.size() ; i+=k){
                int sum = 0 ;
                for(int j = i ; j < min(i+k , (int)s.size()); j++){
                    sum+= s[j]-'0';
                }
                temp+=to_string(sum);
            }
            s=temp;
        }
        return s;
    }
};

// 111 112 222 23
// 3    4   6   5
// 346 5
// 13 5
// 135