class Solution {
public:
    int binarySearch(vector<vector<int>>& arr, int n, int val) {
        int i = 0, j = n-1, ans = -1;

        while(i <= j) {
            int mid = (i+j)/2;

            if(arr[mid][0] <= val) {
                ans = mid;
                i = mid+1;
            }
            else j = mid-1;
        } 

        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int maxi = 0, n = items.size();

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, items[i][1]);

            items[i][1] = maxi;
        }

        vector<int> ans;
        for(auto i : queries) {
            int idx = binarySearch(items, n, i);
            if(idx == -1) ans.push_back(0);
            else ans.push_back(items[idx][1]);
        }

        return ans;
    }
};