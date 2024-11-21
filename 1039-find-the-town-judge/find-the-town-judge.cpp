class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> freq(n+1, 0);

        for(auto i : trust) freq[i[1]]++;

        int ans = -1;
        for(int i = 1; i <= n; i++) if(freq[i] == n-1) ans = i;

        for(auto i : trust) if(i[0] == ans) return -1;

        return ans;
    }
};