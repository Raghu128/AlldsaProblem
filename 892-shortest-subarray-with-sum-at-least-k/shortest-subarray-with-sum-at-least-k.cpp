class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = n+1;
        long long int sum = 0;
        deque< pair<long long int,int> > pq;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum >= k) ans = min(ans, i+1);

            while(!pq.empty() && (sum - pq.front().first) >= k) {
                pair<int,int> top = pq.front(); pq.pop_front();

                ans = min(ans, i-top.second);
            }

            while (!pq.empty() && pq.back().first > sum) {
                pq.pop_back();
            }

            pq.push_back({sum, i});
        }

        if(ans == (n+1)) return -1;
        return ans;
    }
};