class Solution {
public:
    bool solve(int idx, string s, unordered_set<string>& dict, vector<int>& dp) {
        int n = s.size();
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        
        string a = "";
        bool ans = false;
        for(int i = idx; i < n; i++) {
            a += s[i];

            if(dict.find(a) != dict.end()) ans = ans || solve(i+1, s, dict, dp);
        }

        return dp[idx] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i : wordDict) st.insert(i);

        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, st, dp);
    }
};