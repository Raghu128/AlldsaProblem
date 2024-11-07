class Solution {
public:
    vector<int> setBit(int n) {
        int i = 0;
        vector<int> ans(32, 0);
        while(n) {
            if(n&1) ans[i] = 1;
            i++;
            n = n >> 1;
        }

        return ans;
    }
    bool check(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 32; i++) if(a[i] && b[i]) return true;
        return false;
    }
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<vector<int>> candSetBit(n, vector<int>(32, 0));
        for(int i = 0; i < n; i++) {
            candSetBit[i] = setBit(candidates[i]);
        }

        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(candSetBit[j][i] == 1) cnt++;
            }

            ans = max(ans, cnt);
        }
        
        return ans;
    }
};