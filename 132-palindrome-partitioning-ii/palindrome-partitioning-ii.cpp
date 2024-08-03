class Solution {
public:
     bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        // string a = "";
        // string b = "";
        int ans = n;
        for(auto idx = i; idx < n; idx++) {
            // a = a+s[idx];
            // b = s[idx] + b;

            // if(a == b) {
            //     ans = min(ans, solve(idx+1, s, dp) + 1);
            // }
            if(isPalindrome(i, idx, s)) {
                ans = min(ans, solve(idx+1, s, dp) + 1);
            }
        }

        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        int ans = solve(0, s, dp)-1;
        return ans;
    }
};