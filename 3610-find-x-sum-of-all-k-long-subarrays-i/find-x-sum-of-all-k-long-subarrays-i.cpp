class Solution {
public:
    int solve(vector<int> arr, int x) {
        priority_queue< pair<int,int> > pq;
        for(auto i = 1; i < 51; i++) if(arr[i]) pq.push({arr[i], i});
        
        int ans = 0;
        while(pq.size() && x--) {
            auto top = pq.top(); pq.pop();
            cout << top.first << " " << top.second << endl;

            ans += top.first*top.second;
        }

        return ans;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> freq(51, 0);
        int n = nums.size();

        for(auto i = 0 ; i < k; i++) freq[nums[i]]++;

        vector<int> ans;
         ans.push_back(solve(freq, x));
        for(auto i = k; i < n; i++) {
            freq[nums[i-k]]--;
            freq[nums[i]]++;
            ans.push_back(solve(freq, x));
        }

        return ans;
    }


};