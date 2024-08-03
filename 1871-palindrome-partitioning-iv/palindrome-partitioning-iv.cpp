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
    bool solve(int i, int cuts, string& s, vector<vector<int>>& dp) {
        int n = s.size();
        // if(cuts == 0) return true;
        if(i == n) return false;
        if(dp[i][cuts] != -1) return dp[i][cuts];

        // string a = "";
        // string b = "";

        if(cuts == 0) {
            return dp[i][cuts] = isPalindrome(i, n-1, s);
            // for(int idx = i; idx < n; idx++) {
            //      a += s[idx];
            //     b = s[idx] + b;
            // }

            // return dp[i][cuts] = a == b;
        }
        for(int idx = i; idx < n; idx++) {
            // a += s[idx];
            // b = s[idx] + b;

            if(isPalindrome(i, idx, s)) {
                // cout << a << endl;
                bool ans = solve(idx+1, cuts-1, s, dp);
                if(ans == true) return dp[i][cuts] = true;
            }
        }

        return dp[i][cuts] = false;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return solve(0, 2, s, dp);
    }
};