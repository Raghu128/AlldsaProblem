class Solution {
public:
    bool solve(int i, int j, string s, int n, string p, int m, vector<vector<int>>& memo) {
        if(i == n && j == m) return true;
        if(j == m) return false;
        if(i == n) {
            while(j < m){
                if(j + 1 < m && p[j+1] != '*') {
                    return false;
                }
                j += 2;
            }
            if(p[m-1] != '*') return false;
            return true;
        }

        if(memo[i][j] != -1) return memo[i][j];
        
        if(j + 1 < m && p[j+1] == '*') {
            if(p[j] == '.' || p[j] == s[i]) return memo[i][j] = solve(i+1, j, s, n, p, m, memo) || solve(i, j+2, s, n, p, m, memo);
            return memo[i][j] = solve(i, j+2, s, n, p, m, memo);
        }
        else if(p[j] == '.') {
            return memo[i][j] = solve(i+1, j+1, s, n, p, m, memo) ;
        }

        if(p[j] == s[i]) return memo[i][j] = solve(i+1, j+1, s, n, p, m, memo);
        return memo[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, n, p, m, memo);
    }
};