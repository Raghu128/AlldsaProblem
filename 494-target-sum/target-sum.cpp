class Solution {
public:
    int solve(int i, int target, vector<int>& arr) {
        if(i == arr.size()) {
            if(target == 0) return 1;
            return 0;
        }

        int c1 = solve(i+1, target-arr[i], arr);
        int c2 = solve(i+1, target+arr[i], arr);

        return c1+c2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};