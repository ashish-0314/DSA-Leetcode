class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1,true);
        prime[0]=prime[1] = false;
        for(int i = 2 ; i*i <= right ; i++ ){
            if(prime[i]){
                for(int j = i*i ; j <= right ; j+=i){
                    prime[j]=false;
                }
            }
        }
        int prev = -1 ;
        vector<int> ans = {-1,-1};
        int mini = INT_MAX;
        for(int i = left ; i <= right ; i++){
            if(!prime[i]) continue;
            if(prev != -1 && i - prev < mini){
                mini = i - prev ;
                ans = {prev,i};
            }
            prev = i ;
        }
        return ans;
    }
};