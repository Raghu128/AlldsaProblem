class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        if(n == 1) return {nums[0]};

        vector<int> dp(n+1, 1);
        sort(nums.begin(), nums.end());

        int maxi = 0;


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    dp[i] = max(dp[i], dp[j]+1);
                    if(dp[maxi] < dp[i]) maxi = i;
                }
            }
        }

        // for(auto i : dp) cout << i << " ";
        // cout << endl;
        vector<int> ans;
        ans.push_back(nums[maxi]);
        int cnt = dp[maxi]-1;
        int prev = nums[maxi];
        for(int i = maxi-1; i >= 0; i--) {
            if(dp[i] == cnt && (prev % nums[i] == 0 || nums[i] % prev == 0)) {
                cnt--;
                ans.push_back(nums[i]);
                prev = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};