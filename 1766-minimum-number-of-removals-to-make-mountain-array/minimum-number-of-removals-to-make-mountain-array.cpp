class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(nums[i] < nums[j]) left[j] = max(left[j], left[i] + 1);
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                if(nums[i] < nums[j]) right[j] = max(right[j], right[i] + 1);
            }
        }
        // for(int i : left) cout << i << " ";
        // cout << endl;
        // for(int i : right) cout << i << ' ';

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(left[i] && right[i])
                ans = max(ans, left[i]+right[i]+1);
        }
        return n-ans;

    }
};