class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size(), m = mat[0].size();
        if(i == n || j == m || mat[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];


        int right = solve(i, j+1, mat, dp);
        int diag = solve(i+1, j+1, mat, dp);
        int bottom = solve(i+1, j, mat, dp);

        return dp[i][j] = min(right, min(diag, bottom)) + 1;

    }
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) ans += solve(i, j, mat, dp);
            }
        }

        return ans;
    }
};