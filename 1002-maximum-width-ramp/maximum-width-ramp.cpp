class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        stack<pair<int,int>> st;
        st.push(arr[0]);
        for(int i = 1; i < n; i++) {
            if(arr[i].second < st.top().second) {
                st.push(arr[i]);
            }
            else {
                ans = max(ans, arr[i].second - st.top().second);
            }
        }

        return ans;

    }
};