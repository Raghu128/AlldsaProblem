class Solution {
public:
    int solve(int ele, int mask, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(ele > 100) return 0;
        if(dp[ele][mask] != -1) return dp[ele][mask];

        int m = arr[ele].size();
        int take = 0, notTake = solve(ele+1, mask, arr, dp);

        for(int i : arr[ele]) {
            if(((1 << i) & mask) == 0)
                take = max(take, ele + solve(ele+1, mask | (1 << i), arr, dp));
        }

        return dp[ele][mask] = max(take, notTake);
    }
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> arr(101);
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[grid[i][j]].push_back(i);
            }
        }

        vector<vector<int>> dp(101, vector<int>(1024, -1));
        return solve(0, 0, arr, dp);
    }
};