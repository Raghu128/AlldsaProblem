class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, cnt = 0, n = nums.size(), prev = 0;

        int i = 0;
        while(i < n) {
            if(nums[i] == 0) cnt++;

            while(prev < i && cnt > k) {
                if(nums[prev] == 0) cnt--;
                prev++;
            }

            if(i == prev && nums[i] == 0) {
                ans = max(ans, k);
            }
            else ans = max(ans, i-prev+1);
            i++;
        }

        // if(ans == 0) return k;

        return ans;
    }
};