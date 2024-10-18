class Solution {
public:
    int solve(int i, int currVal, int tar, vector<int>& a, int n, vector<vector<int>> &dp) {
        if(i == n) {
            if(currVal == tar) return 1;
            return 0;
        }
        if(dp[i][currVal] != -1) return dp[i][currVal];

        int take = solve(i+1, currVal | a[i], tar, a, n, dp);
        int notTake = solve(i+1, currVal, tar, a, n, dp);

        return dp[i][currVal] = take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(auto i : nums) maxi |= i;

        vector<vector<int>> dp(n+1, vector<int>(maxi+1, -1));
        return solve(0, 0, maxi, nums, n, dp);


    }
};