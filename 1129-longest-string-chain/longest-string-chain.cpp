class Solution {
public:
    static bool cmp(string& a, string& b) {
        int n = a.size(), m = b.size();
        if(n == m) return a < b;
        return n < m; 
    }
    bool same(string& a, string& b) {
        int n = a.size(), m = b.size();
        if(abs(n-m) != 1) return false;
        int idx = 0;
        for(auto i : a) {
            if(idx == b.size()) return false;
            while(idx < b.size() && b[idx] != i) idx++;
            if(idx == b.size()) return false;
            idx++;
        }

        return true;
    }
    int solve(int i, int prev, vector<string>& word, vector<vector<int>>& dp) {
        if(i == word.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];


        int n = 0;
        string a = "";
        string b = "";
        if(prev != 0) {
            n = min(word[i].size(), word[prev-1].size());
            if(word[i].size() < word[prev-1].size()) {
                a = word[i];
                b = word[prev-1];
            }
            else {
                b = word[i];
                a = word[prev-1];
            }
        }
        int incl = 0, excl = 0;
        if(prev == 0 || same(a, b)) {
            incl = solve(i+1, i+1, word, dp) + 1;
        }

        excl = solve(i+1, prev, word, dp);

        return dp[i][prev] = max(incl, excl);
    }

    int solveTab(vector<string>& word) {
        sort(word.begin(), word.end(), cmp);
        int s = word.size();
        int maxi = 0;
        vector<int> dp(s+1, 0);
        for(int i = 0; i < s; i++) {
            for(int prev = 0; prev < i; prev++) {

                if(same(word[prev], word[i]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                    maxi = max(maxi, dp[i]);
                }
                
            }
        }

        return maxi+1;
    }


    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        
        return solveTab(words);

        int n = words.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, 0, words, dp);
    }
};