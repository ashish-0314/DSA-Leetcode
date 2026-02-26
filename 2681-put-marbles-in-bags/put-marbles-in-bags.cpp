class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> sumi(n-1);
        for(int i = 0 ; i< n-1 ; i++){
            sumi[i] =(long long)weights[i] + weights[i+1];
        }
        sort(sumi.begin(),sumi.end());
        long long mini = 0 ;
        long long maxi = 0 ;
        for(int i = 0 ; i < k-1 ; i++){
            mini+=sumi[i];
            maxi+=sumi[n-1-i-1];
        }
        return maxi-mini;
    }
};