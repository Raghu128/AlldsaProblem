class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector< pair<double,double> > arr;
        int n = speed.size();
        for(int i = 0; i < n; i++) arr.push_back({position[i], speed[i]});

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        vector<double> timeStamp(n);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            timeStamp[i] = (target-arr[i].first)/arr[i].second*1.0;

            if(i > 0 && timeStamp[i-1] >= timeStamp[i]) timeStamp[i] = timeStamp[i-1];
            else ans++;
        }

        return ans;
    }
};