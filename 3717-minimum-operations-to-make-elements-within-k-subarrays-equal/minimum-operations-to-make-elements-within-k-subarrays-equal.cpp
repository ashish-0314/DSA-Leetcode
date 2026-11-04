
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        // Insert element into the correct half
        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }
        };

        // Remove element from the window
        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }
        };

        // Balance both halves
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();

                low.erase(prev(low.end()));
                high.insert(val);

                sumLow -= val;
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();

                high.erase(high.begin());
                low.insert(val);

                sumHigh -= val;
                sumLow += val;
            }
        };

        // Sliding window
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            balance();

            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long operations =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();

                cost.push_back(operations);
            }
        }

        // DP
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element
                curr[i] = curr[i - 1];

                // Select window of size x
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};


//isko baad me solve krunga . copy paste hai yeh 