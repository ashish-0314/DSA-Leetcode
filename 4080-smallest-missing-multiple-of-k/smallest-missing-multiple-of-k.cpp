class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]=i;
        }
        int i = 1 ;
        while(true){
            if(!mp.count(k*i)){
                return k*i;
                break;
            }
            i++;
        }
        return -1;
    }
};