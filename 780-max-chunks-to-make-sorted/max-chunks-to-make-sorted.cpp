class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int idx = 0, ans = 0;
        vector< pair<int,int> > num;

        for(int i = 0; i < n; i++) num.push_back({arr[i], i});
        sort(num.begin(), num.end());

        for(int i = 0; i < n; i++) {
            if(idx > i) {
                idx = max(idx, num[i].second+1);
            }
            else {
                ans++;
                idx = num[i].second+1;
                // cout << idx << endl;
            }
        }

        return ans;
    }
};