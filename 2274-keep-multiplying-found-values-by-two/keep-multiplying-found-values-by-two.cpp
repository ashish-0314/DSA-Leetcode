class Solution {
public:
    bool isPresent(vector<int>& nums, int og){
        for(int num: nums) if(num==og) return true;
        return false;
    }
    int findFinalValue(vector<int>& nums, int og) {
        while(isPresent(nums,og)) og*=2;
        return og;
    }
}; 