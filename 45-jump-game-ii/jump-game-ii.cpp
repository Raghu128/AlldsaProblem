class Solution {
public:

    int solve(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx == n-1) return 0;
        if(idx >= n) return n;

        int len = nums[idx];
        int ans = n;
        for(int i = 1; i <= len; i++) {
            if(idx + i < n) {
                ans = min(ans, 1+solve(idx+i, nums));
            }
            else break;
        }

        return ans;
    }

    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, n);
        dp[n-1] = 0;

        for(int idx = n-2; idx >= 0; idx--) {
            int len = nums[idx];
            int ans = n;
            for(int i = 1; i <= len; i++) {
                if(idx + i < n) {
                    ans = min(ans, 1 + dp[idx+i]);
                }
                else break;
            }

            dp[idx] = ans;
        }

        return dp[0];
    }


    int jump(vector<int>& nums) {
        return solveTab(nums);
        return solve(0, nums);
    }
};