class Solution {
public:
    int maxProduct(int n) {
        vector<int> s;
        while(n>0){
            int digit=n%10;
            s.push_back(digit);
            n/=10;
        }
        int first=INT_MIN;
        int second=INT_MIN;

        for(int i=0;i<s.size();i++){
            if(s[i]>first){
                second=first;
                first=s[i];
            }
            else if(s[i]>second ){
                second=s[i];
            }
        }
        return (second==INT_MIN)?(-1):second*first;
    }
};