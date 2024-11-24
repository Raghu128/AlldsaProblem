class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX, n = nums.size();

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];

                if(sum > 0 && (j-i+1) >= l && (j-i+1) <= r) {
                    ans = min(ans, sum);
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};