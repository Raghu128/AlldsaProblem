class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        deque<pair<int,int>> dq;
        for(int i = 0; i < k; i++) {
            if(dq.empty() || (dq.back().first + 1) == nums[i]) dq.push_back({nums[i], i});
            else {
                dq.clear();
                dq.push_back({nums[i], i});
            }
        }

        if(dq.size() == k) ans.push_back(dq.back().first);
        else ans.push_back(-1);

        for(int i = k; i < n; i++) {
            while(!dq.empty() && dq.front().second <= i-k) dq.pop_front();
            
            if(dq.empty() || (dq.back().first + 1) == nums[i]) dq.push_back({nums[i], i});
            else {
                dq.clear();
                dq.push_back({nums[i], i});
            }

            if(dq.size() == k) ans.push_back(dq.back().first);
            else ans.push_back(-1);
        }
       


        return ans;
    }
};