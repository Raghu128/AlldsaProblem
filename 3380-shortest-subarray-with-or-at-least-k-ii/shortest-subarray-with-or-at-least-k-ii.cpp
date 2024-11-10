class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> freq(32, 0);

        int bitOr = 0, back = 0, front = 0;
        while(front < n) {
            for(int i = 0; i < 32; i++) {
                int pos = (1 << i);
                if(nums[front]&pos) {
                    freq[i]++;
                    if(freq[i] == 1) bitOr += pos;
                }
            }

            while(bitOr >= k && back <= front) {
                for(int i = 0; i < 32; i++) {
                    int pos = (1 << i);
                    if(nums[back]&pos) {
                        freq[i]--;
                        if(freq[i] == 0) bitOr -= pos;
                    }
                }
                ans = min(ans, front-back+1);
                back++;
            }
            front++;
        }

        if(ans <= n) return ans;
        return -1;
    }
};