class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> freq(n, 0);

        for(auto edge : edges) {
            freq[edge[1]]--;
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(freq[i] == 0) {
                if(ans != -1) return -1;
                ans = i;
            }
        }

        return ans;
    }
};