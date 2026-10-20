class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
       int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = 0;

            for (int start = 0; start < n; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int drops = 0;

                for (int i = start; i < start + k; i++) {
                    int next = (i + 1 == start + k)
                               ? start : i + 1;

                    if (nums[i] > nums[next])
                        drops++;

                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }

                if (drops > 1 || prevMax > mn) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    } 
    
};