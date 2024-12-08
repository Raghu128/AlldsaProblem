class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int maxi = 0;
        int maxVal = 0;

        for(auto i : events) {
            int start = i[0], end = i[1], val = i[2];
            while(!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxi = max(maxi, maxVal+val);

            pq.push({end, val});
        }

        return maxi;
    }
};