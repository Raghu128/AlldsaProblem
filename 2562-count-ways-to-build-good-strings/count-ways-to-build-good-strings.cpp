class Solution {
public:
    int solve(int len, int zero, int one, int low, int high, vector<int>& dp) {
        // If length exceeds the maximum limit, return 0
        if (len > high) return 0;

        // If the result for the current length is already computed, return it
        if (dp[len] != -1) return dp[len];

        // Compute results for taking 'zero' and 'one'
        int takeOne = solve(len + one, zero, one, low, high, dp);
        int takeZero = solve(len + zero, zero, one, low, high, dp);

        // Add counts if the length falls within the [low, high] range
        if (len + one >= low && len + one <= high) takeOne += 1;
        if (len + zero >= low && len + zero <= high) takeZero += 1;

        // Store the result in the memoization table and return it
        return dp[len] = (takeOne + takeZero) % 1000000007;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Memoization table to store results for lengths from 0 to high
        vector<int> dp(high + 1, -1);
        return solve(0, zero, one, low, high, dp);
    }
};
