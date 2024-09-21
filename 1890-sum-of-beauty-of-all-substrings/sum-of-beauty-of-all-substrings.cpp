class Solution {
public:
    int solve( vector<int>& freq) {
        int mini = 501, maxi = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            mini = min(mini, freq[i]);
            maxi = max(maxi, freq[i]);
        }

        return maxi - mini;
    }
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
           vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                 freq[s[j]-'a']++;

                ans += solve(freq);
            }
        }

        return ans;
    }
};