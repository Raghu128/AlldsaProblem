class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();

        unordered_map<int,long long> cnt, sum;
        
        for(auto i : nums) {
            cnt[i] += (cnt[i - 1] + cnt[i + 1] + 1) % mod;
            cnt[i] %= mod;

            sum[i] += (sum[i - 1] + sum[i + 1]) % mod;
            sum[i] %= mod;
            
            sum[i] += (long long)(cnt[i - 1] + cnt[i + 1] + 1) % mod * i % mod;
            sum[i] %= mod;
        }

        int ans = 0;
        for(auto i : sum) {
            ans = (ans + i.second%mod)%mod;
        }
        
        return ans;
    }
};