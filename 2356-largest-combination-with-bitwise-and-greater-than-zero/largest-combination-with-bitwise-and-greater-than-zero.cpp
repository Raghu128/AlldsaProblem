class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int ans = 0;

        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto j : candidates) {
                if((1 << i )& j) cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};