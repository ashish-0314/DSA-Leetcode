class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // already sorted
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) { sorted = false; break; }
        }
        if (sorted) return 0;

        // length 2 and unsorted: impossible
        if (n == 2) return -1;

        char mn = 'z', mx = 'a';
        for (char ch : s) {
            if (ch < mn) mn = ch;
            if (ch > mx) mx = ch;
        }

        // first is smallest -> sort s[1..], last is largest -> sort s[0..n-2]
        if (s[0] == mn || s[n - 1] == mx) return 1;

        int maxCnt = 0, minCnt = 0;
        for (char ch : s) {
            if (ch == mx) maxCnt++;
            if (ch == mn) minCnt++;
        }
        // first is unique largest AND last is unique smallest
        if (s[0] == mx && maxCnt == 1 && s[n - 1] == mn && minCnt == 1) return 3;

        return 2;
    }
};