class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size()-1;
        digits[n]++;
        for(int i = n ;i>=0; i--){
            if (digits[i] > 9) {
                digits[i] = 0; 
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                } else {
                    digits[i - 1]++;
                }
            }
        }
        return digits;
    }
};