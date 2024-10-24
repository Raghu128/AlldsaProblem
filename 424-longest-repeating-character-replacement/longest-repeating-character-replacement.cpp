class Solution {
public:
    int solve(char ch, string nums, int n, int k) {
        int cnt = 0, prev = 0, i = 0, ans = 0;

        while(i < n) {
            if(nums[i] != ch) cnt++;

            while(prev < i && cnt > k) {
                if(nums[prev] != ch) cnt--;
                prev++;
            }

            if(i == prev && nums[i] != ch) {
                ans = max(ans, k);
            }
            else ans = max(ans, i-prev+1);
            i++;
        }


        return ans;

    }
    int characterReplacement(string s, int k) {
        int ans = k, n = s.size();

        for(auto i = 'A'; i <= 'Z'; i++) ans = max(ans, solve(i, s, n, k));

        return ans;
    }
};