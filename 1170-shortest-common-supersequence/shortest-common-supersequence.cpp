class Solution {
public:
    string ans;
    void solve(int i, int j, string str, string& a, string& b, vector<vector<int>>& dp) {
        if(i == a.size() && j == b.size()) {
            // cout << str << endl;
            ans = str;
            // ans.insert(str);
            return;
        }
        if(i == a.size()) {
            // cout << "j ->" << j << endl;
            for(int idx = j; idx < b.size(); idx++) {
                str += b[idx];
            }

             ans = str;
            return;
        }
        if(j == b.size()) {
            // cout << "i ->" << i << endl;
            for(int idx = i; idx < a.size(); idx++) {
                str += a[idx];
            }

             ans = str;
            return;
        }
        // cout << i << " " << j << endl;
        if(a[i] == b[j]) solve(i+1, j+1, str+a[i], a, b, dp);
        else {
                int right = dp[i][j+1];
                int bottom = dp[i+1][j];
                
                if(right == bottom) {
                    solve(i+1, j, str+a[i], a, b, dp);
                    // solve(i, j+1, str, a, b, dp);
                }
                else if(right < bottom) {
                    solve(i+1, j, str + a[i], a, b, dp);
                }
                else solve(i, j+1, str + b[j], a, b, dp);
                
        }
    }
    void solveTab(string& text1, string& text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i = n1-1; i >= 0; i--) {
            for(int j = n2-1; j >= 0; j--) {

                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] =  max(dp[i+1][j], dp[i][j+1]);

            }
        }
        
        // vector<string> ans;
        // for(auto i : dp) {
        //     for(auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        
        solve(0, 0, "", text1, text2, dp);
        
        
        return ;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        // ans = str1 + str2;
        // int n = str1.size(), m = str2.size();
        // solve(n-1, m-1, "", str1, str2);
        solveTab(str1, str2);

        return ans;
    }
};