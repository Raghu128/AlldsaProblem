class Solution {
public:
    bool check(int i, int j, int n, int m) {
        if(i == -1 || i == n) return 0;
        if(j == m || j == -1) return 0;
        
        return true;
    }
    int solve(int i, int j, vector<vector<int>>& arr, int n, int m, vector<vector<int>>& dp) {
        if(i == -1 || i == n) return 0;
        if(j == m || j == -1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(check(i-1, j+1, n, m) && arr[i][j] < arr[i-1][j+1])
            ans = max(ans, solve(i-1, j+1, arr, n, m, dp));

        if(check(i+1, j+1, n, m) && arr[i][j] < arr[i+1][j+1])
            ans = max(ans, solve(i+1, j+1, arr, n, m, dp));

        if(check(i, j+1, n, m) && arr[i][j] < arr[i][j+1])
            ans = max(ans, solve(i, j+1, arr, n, m, dp));

        return dp[i][j] = ans + 1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0; i < n; i++) ans = max(ans, solve(i, 0, grid, n, m, dp));

        return ans-1;
    }
};