class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans = 0;

        for(auto i : nums) pq.push(i);

        while(!pq.empty() && k--) {
            int top = pq.top(); pq.pop();
            cout << top << endl;
            ans += top;
            pq.push(ceil(top/3.0));
        }

        return ans;
    }
};