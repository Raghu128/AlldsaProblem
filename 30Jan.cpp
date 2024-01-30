/*
Problem --> LCS of three strings
Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

Example 1:

Input:
A = "geeks"
B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: 
"geeks"is the longest common
subsequence with length 5.
Example 2:

Input: 
A = "abcd"
B = "efgh"
C = "ijkl"
Output: 0
Explanation: 
There's no subsequence common
in all the three strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings consitutes only of the lower case english alphabets.

*/

class Solution
{
    public:
        int solve(int i, int j, int k, string a, string b, string c) {
            if(i == a.size() || j == b.size() || k == c.size()) return 0;
            
            if(a[i] == b[j] && b[j] == c[k]) return 1 + solve(i+1, j+1, k+1, a, b, c);
            
            int ans = 0;
            
            ans = max(ans, solve(i+1, j, k, a, b, c));
            ans = max(ans, solve(i, j+1, k, a, b, c));
            ans = max(ans, solve(i, j, k+1, a, b, c));
            
            return ans;
        }
        
        int solveTab(string& a, string& b, string& c) {
            int n1 = a.size(), n2 = b.size(), n3 = c.size();
            vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, 0)));
            
            for(int i = n1-1; i >= 0; i--) {
                for(int j = n2-1; j >= 0; j--) {
                    for(int k = n3-1; k >= 0; k--) {
                        int ans = 0;
                        
                        if(a[i] == b[j] && b[j] == c[k]) ans = 1 + dp[i+1][j+1][k+1];
                        else {
                            ans = max(ans, dp[i+1][j][k]);
                            ans = max(ans, dp[i][j+1][k]);
                            ans = max(ans, dp[i][j][k+1]);
                        }
                        
                        dp[i][j][k] = ans;
                    }
                }
            }
            
            return dp[0][0][0];
        }
        
        int solveTabOpt(string& a, string& b, string& c) {
            int n1 = a.size(), n2 = b.size(), n3 = c.size();
            vector<vector<int>> curr(n2+1, vector<int>(n3+1, 0));
            vector<vector<int>> prev(n2+1, vector<int>(n3+1, 0));
            
            for(int i = n1-1; i >= 0; i--) {
                for(int j = n2-1; j >= 0; j--) {
                    for(int k = n3-1; k >= 0; k--) {
                        int ans = 0;
                        
                        if(a[i] == b[j] && b[j] == c[k]) ans = 1 + prev[j+1][k+1];
                        else {
                            ans = max(ans, prev[j][k]);
                            ans = max(ans, curr[j+1][k]);
                            ans = max(ans, curr[j][k+1]);
                        }
                        
                        curr[j][k] = ans;
                    }
                    
                }
                prev = curr;
            }
            
            return curr[0][0];
        }
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {   
            
            return solveTabOpt(A, B, C);
            return solve(0, 0, 0, A, B, C);
        }
};
