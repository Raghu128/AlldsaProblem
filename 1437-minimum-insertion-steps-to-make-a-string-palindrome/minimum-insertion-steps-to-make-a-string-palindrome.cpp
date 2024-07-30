class Solution {
public:
    int solve(int i,int j, string& s, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = solve(i+1, j-1, s, dp);

        int case1 = solve(i+1, j, s, dp);
        int case2 = solve(i, j-1, s, dp);

        return dp[i][j] = min(case2, case1) + 1;
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s, dp);
    }
};