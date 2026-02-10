class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n) ;
        int pidx = 0 , nidx = 1;
        for(int num: nums){
            if(num>0){
                res[pidx]=num;
                pidx+=2;
            }
            else{
                res[nidx]=num;
                nidx+=2;
            }
        }
        return res;
    }
};