class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,bool> mp;
        unordered_map<long long ,int> freq;

        int n = nums.size();
        long long sum = 0;
        int start = 0, last = 0;

        while(last < n) {
            sum += nums[last];

            while(mp[nums[last]] == true) {
                sum -= nums[start];
                mp[nums[start]] = false;
                start++;
            }

            mp[nums[last]] = true;
            last++;
            if((last-start) == k) {
                freq[sum]++;
                sum -= nums[start];
                mp[nums[start]] = false;
                start++;
            }
        }

        long long ans = 0;
        for(auto i : freq) {
            ans = max(ans, i.first);
        }
        return ans;
    }
};