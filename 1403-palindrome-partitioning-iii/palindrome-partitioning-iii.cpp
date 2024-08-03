class Solution {
public:
    int isPalindrome(int i, int j, string &s) {
        int ans = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                ans++;
            }
            i++;
            j--;
        }
        return ans;
    }
    int solve(int idx, int k, string& s, vector<vector<int>>& dp) {
        int n = s.size();
        if(idx == n) return n;
        if(dp[idx][k] != -1) return dp[idx][k];

        if(k == 1) {
            int change = isPalindrome(idx, n-1, s);
            return dp[idx][k] = change;
        }

        int ans = n;
        for(int i = idx; i < n; i++) {
            int change = isPalindrome(idx, i, s);

            ans = min(ans, change + solve(i+1, k-1, s, dp));
        }

        return dp[idx][k] = ans;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(0, k, s, dp);
    }
};