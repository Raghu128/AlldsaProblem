class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,bool> mp;
        long long ans = 0;

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
                ans = max(ans, sum);
                sum -= nums[start];
                mp[nums[start]] = false;
                start++;
            }
        }

        
        return ans;
    }
};