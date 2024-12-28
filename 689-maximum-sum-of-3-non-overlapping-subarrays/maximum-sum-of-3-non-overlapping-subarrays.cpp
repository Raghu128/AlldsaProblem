class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        
        // Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // Left max sum
        vector<int> left(n, 0);
        int maxSum = prefixSum[k] - prefixSum[0];
        left[k - 1] = 0;
        for (int i = k; i < n; ++i) {
            int currentSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }

        // Right max sum
        vector<int> right(n, 0);
        maxSum = prefixSum[n] - prefixSum[n - k];
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            int currentSum = prefixSum[i + k] - prefixSum[i];
            if (currentSum >= maxSum) {
                maxSum = currentSum;
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }

        // Find max sum of three subarrays
        vector<int> result(3, 0);
        maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1];
            int r = right[i + k];
            int total = (prefixSum[i + k] - prefixSum[i]) +
                        (prefixSum[l + k] - prefixSum[l]) +
                        (prefixSum[r + k] - prefixSum[r]);
            if (total > maxSum) {
                maxSum = total;
                result = {l, i, r};
            }
        }

        return result;
    }
};
