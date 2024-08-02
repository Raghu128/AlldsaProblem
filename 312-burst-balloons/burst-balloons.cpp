class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(i == j) return nums[i-1] * nums[i] * nums[i+1];

        int ans = 0;
        for(int idx = i; idx <= j; idx++) {
            ans = max( ans, nums[i-1]*nums[idx]*nums[j+1] + solve(i, idx-1, nums) + solve(idx+1, j, nums) );
        }

        return ans;
    }

    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-2; i >= 1; i--) {
            for(int j = i; j < n-1; j++) {
                 int ans = 0;
                for(int idx = i; idx <= j; idx++) {
                    ans = max( ans, nums[i-1]*nums[idx]*nums[j+1] + dp[i][idx-1] + dp[idx+1][j] );
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][n-2];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return solveTab(nums);
        // int n = nums.size();
        // int ans = solve(1, n-2, nums);
        // return ans;
    }
};