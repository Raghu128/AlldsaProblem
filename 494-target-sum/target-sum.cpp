class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> memo(n+1);
        memo[n][0] = 1;

        for(int idx = n-1; idx >= 0; idx--) {
            for(int tar = -2000; tar <= 2000; tar++) {
                int sub = 0, add = 0;

                sub = memo[idx+1][tar-nums[idx]];
                add = memo[idx+1][tar+nums[idx]];

                memo[idx][tar] = add + sub;
            }
        }

        return memo[0][target];
    }
};