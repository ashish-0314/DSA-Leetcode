class Solution {
public:
    bool isFascinating(int n) {
        string str = to_string(n) + to_string(n*2) + to_string(n*3);
        int arr[10] ={0};
        for(int i = 0 ; i< str.size() ; i++) arr[str[i]-'0']++;
        if(arr[0]>0) return false;
        for(int i = 1 ; i< 10 ; i++) if(arr[i]!= 1) return false;
        return true;
    }
};