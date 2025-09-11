class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long result = 0;
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            string sa = to_string(nums[i]);
            string sb = to_string(nums[j]);
            result += stoi(sa + sb);
            i++;
            j--;
        }
 
        if (i == j)  result += nums[i];
        return result;
    }
};
