class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int size = banned.size();

        unordered_set<int> st;
        for(auto i : banned) if(i <= n) st.insert(i);

        int sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(st.count(i) == 0) {
                if((sum + i) <= maxSum) {
                    sum += i;
                   cnt++;
                }
            }
        }

        return cnt;
    }
};