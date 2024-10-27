class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long int mod = 1e9+7;
        vector< long long int > freq(26, 0);

        for(auto i : s) freq[i-'a']++;

        for(int i = 0; i < t; i++) {
            vector< long long int > nextFreq(26, 0);
            for(auto j = 0; j < 26; j++) {
                long long int cnt = freq[j];
                freq[j] = 0;
                if(j == 25) {
                    nextFreq[1] += (cnt)%mod;
                    nextFreq[0] += (cnt)%mod;
                }
                else nextFreq[j+1] += cnt;
            }

            freq = nextFreq;
        }

        int ans = 0;
        for(auto i = 0; i < 26; i++) ans = (ans + freq[i])%mod;

        return ans;
    }
};