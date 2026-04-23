class Solution {
public:
    typedef long long ll;

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> arr(n,0);

        unordered_map<int,ll> idxSum;
        unordered_map<int,ll> idxCnt;

        for(int i = 0 ; i < n ; i++){
            ll freq = idxCnt[nums[i]];
            ll sum = idxSum[nums[i]];

            arr[i] += freq*i - sum;

            idxCnt[nums[i]] +=1;
            idxSum[nums[i]] +=i;
        }

        idxSum.clear();
        idxCnt.clear();

        for(int i = n-1 ; i >=0 ; i--){
            ll freq = idxCnt[nums[i]];
            ll sum = idxSum[nums[i]];

            arr[i] += sum - freq*i;

            idxCnt[nums[i]] +=1;
            idxSum[nums[i]] +=i;
        }
        return arr;
    }
};