class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int lb = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            int ub = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin();

            ans += ub-lb;
        }

        return ans;
    }
};