class Solution {
public:
    int ulta(int n){
        int r = 0 ;
        while(n>0){
            int d = n%10;
            r = r*10 + d ;
            n/=10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mini = 1e9;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.count(nums[i])){
                mini = min(mini , i-mp[nums[i]]);
            }  
            mp[ulta(nums[i])] = i ;
        }
        return mini==1e9 ?-1 : mini ;
    }
};