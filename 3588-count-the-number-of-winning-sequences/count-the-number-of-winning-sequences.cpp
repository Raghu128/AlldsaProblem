class Solution {
public:
    char giveDragon(int n) {
        if(n == 0) return 'F';
        if(n == 1) return 'W';
        if(n == 2) return 'E';
        return 'D';
    }

    int solve(int i, int prev, int cnt, string& s, int n, vector<vector<vector<int>>>& dp) {
        long long int mod = 1e9+7;
        if(i == n) {
            // cout << cnt << endl;
            if(cnt > n) return 1;
            return 0;
        }

        if(dp[i][prev][cnt] != -1) return dp[i][prev][cnt];

        int case1 = 0, case2 = 0, case3 = 0;

        if(giveDragon(prev) != 'F') {
            int newCnt = cnt;
            if( s[i] == 'E') newCnt = cnt+1;
            else if(s[i] == 'W') newCnt = cnt-1;
            case1 = solve(i+1, 0, newCnt, s, n, dp);
        }

        if(giveDragon(prev) != 'W') {
            int newCnt = cnt;
            if(s[i] == 'F') newCnt = cnt+1;
            else if(s[i] == 'E') newCnt = cnt-1;
            case2 = solve(i+1, 1, newCnt, s, n, dp);
        }

        if(giveDragon(prev) != 'E') {
            int newCnt = cnt;
            if( s[i] == 'W') newCnt = cnt+1;
            else if(s[i] == 'F') newCnt = cnt-1;
            case3 = solve(i+1, 2, newCnt, s, n, dp);
        }


        return dp[i][prev][cnt] = (case1%mod + case2%mod + case3%mod)%mod;
    }
    int countWinningSequences(string s) {
        int n = s.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(4, vector<int>(2*n + 1, -1)));

        return solve(0, 3, n, s, n, dp);
    }
};