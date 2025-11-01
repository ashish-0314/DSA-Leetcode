class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0 , right = s.size()-1;
        while(left<=s.size()/2){
            s[left]=min(s[left],s[right]);
            s[right]=s[left];
            left++;
            right--;
        } 
        return s;
    }
};