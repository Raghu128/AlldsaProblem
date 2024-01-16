/*
 Problem name --> Sequence of Sequence



Given two integers m and n, try making a special sequence of numbers seq of length n such that

seqi+1 >= 2*seqi 
seqi > 0
seqi <= m
Your task is to determine total number of such special sequences possible.

Example 1:

Input: 
m = 10
n = 4
Output: 
4
Explaination: 
There should be n elements and 
value of last element should be at-most m. 
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
{1, 2, 4, 10}, {1, 2, 5, 10}.
Example 2:

Input: 
m = 5
n = 2
Output: 
6
Explaination: 
The sequences are {1, 2}, 
{1, 3}, {1, 4}, {1, 5}, {2, 4}, {2, 5}.
Your Task:
You do not need to read input or print anything. Your task is to complete the function numberSequence() which takes the number m and n as input parameters and returns the number of possible special sequences.

Expected Time Complexity: O(m*n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ m, n ≤ 100 

*/
#include<iostream>
using namespace std;
#include<vector>
class Solution{
public:
    int solve(int prev, int cnt, int m, int n, vector<vector<int>>& dp) {
        if(cnt == n) return 1;
        if(prev > m) return 0;
        
        if(dp[prev][cnt] != -1) return dp[prev][cnt];
        
        int incl = solve(prev*2, cnt+1, m, n, dp);
        int excl = solve(prev+1, cnt, m, n, dp);
        
        // cout << cnt << ' ';
        
        return dp[prev][cnt] = incl + excl;
    }
    int numberSequence(int m, int n){
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return solve(1, 0, m, n, dp);
    }
};