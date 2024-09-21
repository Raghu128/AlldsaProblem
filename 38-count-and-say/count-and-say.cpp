class Solution {
public:
    string solve(int n) {
        if(n == 1) return "1";

        string subAns = countAndSay(n-1);
        string ans = "";

        char ch = subAns[0];
        int cnt = 0;
        for(auto i : subAns) {
            if(i == ch) {
                cnt++;
            }
            else {
                ans += char('0' + cnt);
                ans += ch;
                ch = i;
                cnt = 1;
            }
        }
        ans += char('0' + cnt);
        ans += ch;

        return ans;
    }
    string solveTab(int size) {
        unordered_map<int,string> dp;
        dp[1] = "1";
        
        for(int n = 2; n <= size; n++) {
            string subAns = dp[n-1];
            string ans = "";

            char ch = subAns[0];
            int cnt = 0;
            for(auto i : subAns) {
                if(i == ch) {
                    cnt++;
                }
                else {
                    ans += char('0' + cnt);
                    ans += ch;
                    ch = i;
                    cnt = 1;
                }
            }
            ans += char('0' + cnt);
            ans += ch;

            // cout << subAns << " " << ans << endl;
            dp[n] = ans;
        }

        return dp[size];
    }
    string countAndSay(int n) {
        return solveTab(n);
        // return solve(n);
    }
};