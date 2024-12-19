class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int idx = 0, ans = 0;
        vector< int > num(n);

        for(int i = 0; i < n; i++) num[arr[i]] = i;

        for(int i = 0; i < n; i++) {
            if(idx > i) {
                idx = max(idx, num[i]+1);
            }
            else {
                ans++;
                idx = num[i]+1;
            }
        }

        return ans;
    }
};