class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int b = n - i;
            string sA = to_string(i), sB = to_string(b);
            if (sA.find('0') == string::npos && sB.find('0') == string::npos) {
                return {i, b};
            }  
        }
        return {};
    }
};
