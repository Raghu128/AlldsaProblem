class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> prefix(n, 0);

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1];
            if(nums[i - 1] % 2 == nums[i] % 2 ) {
                prefix[i]++;
            }
        }

        for(auto i : queries) {
            int start = i[0], last = i[1];
            int total = prefix[last];
            if(start != 0) total -= prefix[start];

            if(total == 0) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};