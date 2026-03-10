class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> a(k,0);
        for(int num: arr){
            int r = ((num%k) + k)%k;
            a[r]++;
        }
        if(a[0]%2 != 0) return false;
        for(int i = 1 ; i <= k/2 ; i++){
            int op = k-i;
            if(a[i] != a[op]) return false;
        }
        return true;
    }
};