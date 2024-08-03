class Solution {
public:
    int solve(int i, vector<int>& arr, int k) {
        int n = arr.size();
        if(i >= n) return 0;

        int ans = 0;
        int maxi = arr[i];
        for(int idx = i; idx < i + k && idx < n; idx++) {
            maxi = max(maxi, arr[idx]);
            ans = max(ans, maxi*(idx-i+1) + solve(idx+1, arr, k));
        }

        return ans;
    }

    int solveTab(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--) {
            int ans = 0;
            int maxi = arr[i];
            for(int idx = i; idx < i + k && idx < n; idx++) {
                maxi = max(maxi, arr[idx]);
                ans = max(ans, maxi*(idx-i+1) + dp[idx+1]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return solveTab(k, arr);
        // int ans = solve(0, arr, k);
        // return ans;
    }
};