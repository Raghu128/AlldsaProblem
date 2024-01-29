/*
Problem --> Count digit groupings of a number

Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings. For example, "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.

A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than the sum of the digits of the sub-group immediately right to it. Your task is to determine the total number of valid groupings that could be done for a given string.

Example 1: 

Input: 
str = "1119"
Output: 
7
Explanation: 
One valid grouping is {"1", "11", "9"}.
Sum of digits of first sub-group ("1") is 1,
for the second sub-group ("11"), it is 2,
and for the third one ("9"), it is 9.
As the sum of digits of the sub-groups is 
in increasing order, it forms a valid grouping.
Other valid grouping are {"1", "119"}, {"1","1","19"}, 
{"1","1","1","9"}, {"11","19"}, {"111","9"} and {"1119"}
are six other valid groupings.
Example 2:

Input: 
str = "12"
Output: 
2
Explanation: 
{"1","2"} and {"12"} are two valid groupings.
Your Task:
You don't need to read or print anything. Your task is to complete the function TotalCount() which takes the string str as input parameter and returns total possible groupings.

Expected Time Complexity: O(N3) where N is the length of the string.
Expected Space Complexity: O(N2)

Constraints:
1 <= N <= 100
stri ∈ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
*/

class Solution{
	public:
	int solve(int index, string& s, int prev) {
	    if(index == s.size()) return 1;
	    int curr = 0, ans = 0;
	    
	    for(int i = index; i < s.size(); i++) {
            curr += (s[i]-'0');
            
	        if(curr >= prev) {
	            ans += solve(i+1, s, curr);
	        }
	    }
	    
	    return ans;
	}
	
	int solveTab(string& s) {
	    int total = 0, n = s.size();
	    for(auto i : s) total += i-'0';
	    
	    vector<vector<int>> dp(n+2, vector<int>(total+1, 0));
	    
	    for(int i = 0; i <= total; i++) dp[n][i] = 1;
	    
	    for(int index = n-1; index >= 0; index--) {
	        for(int prev = total; prev >= 0; prev--) {
	            int curr = 0, ans = 0;
	    
                for(int i = index; i < s.size(); i++) {
                    curr += (s[i]-'0');
                    
                    if(curr >= prev) {
                        ans += dp[i+1][curr];
                    }
                }
                
                dp[index][prev] = ans;
	        }
	    }
	    
	    
	    return dp[0][0];
	}
	
	int TotalCount(string str){
	    return solveTab(str);
	    
	   return solve(0, str, 0);
	}

};
