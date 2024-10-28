class Solution {
public:
    int longestSquareStreak(vector<int>& arr) {
        const int mod = 1e9+7;
        // sort(nums.begin(), nums.end());
        set<int> nums(arr.begin(), arr.end());
        
        int ans = -1, n = nums.size();
        unordered_map< double, int > mp;

        for(auto i : nums) {
            // nums[i] = nums[i]%mod;
            double val = sqrt(i);

            if(mp.find(val) != mp.end()) {
                mp[i] += mp[val]+1;
            }
            else mp[i] = 1;

            ans = max(ans, mp[i]);
        } 


        if(ans < 2) return -1;
        return ans;
    }
};