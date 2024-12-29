class Solution {
public:
    int solve(int idx, int i, string& target, vector<string>& words, vector<vector<int>>& freq, vector<vector<int>>& dp) {
        int n = target.size();
        int eachWordSize = words[0].size();
        
        // Base cases
        if (idx == n) return 1; // Successfully matched the target
        if (i == eachWordSize) return 0; // Exhausted all columns in the words array

        // Check memoization table
        if (dp[idx][i] != -1) return dp[idx][i];

        // Skip this column
        int notTake = solve(idx, i + 1, target, words, freq, dp);

        // Take this column if possible
        int take = 0;
        if (freq[target[idx] - 'a'][i] > 0) {
            take = (long long)freq[target[idx] - 'a'][i] * solve(idx + 1, i + 1, target, words, freq, dp) % 1000000007;
        }

        // Store the result in the memoization table
        return dp[idx][i] = (take + notTake) % 1000000007;
    }

    int numWays(vector<string>& words, string target) {
        int eachWordSize = words[0].size();
        int n = target.size();

        // Frequency array for each character in each column
        vector<vector<int>> freq(26, vector<int>(eachWordSize, 0));
        for (const string& word : words) {
            for (int i = 0; i < eachWordSize; i++) {
                freq[word[i] - 'a'][i]++;
            }
        }

        // Memoization table
        vector<vector<int>> dp(n, vector<int>(eachWordSize, -1));

        // Start the recursion
        return solve(0, 0, target, words, freq, dp);
    }
};
