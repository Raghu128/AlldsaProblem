class Solution {
public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(i == j) return arr[j+1]-arr[i-1];

        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;

        for(int idx = i; idx <= j; idx++) {
            ans = min(ans, solve(i, idx-1, arr, dp) + solve(idx+1, j, arr, dp) + arr[j+1]-arr[i-1]);
        }

        return dp[i][j] = ans;

    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        int s = cuts.size();

        vector<vector<int>> dp(s+1, vector<int>(s+1, -1));
        int ans = solve(1, s-2, cuts, dp);
        return ans;
    }
};