class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int pi = 0, pj = 1, ci = 0, cj = 1, ans = 1;

        while(cj < n) {
            if(nums[cj] <= nums[cj-1]) {
                if(ci == pj) {
                    int lenA = pj - pi, lenB = cj - ci;
                    ans = max(ans, min(lenA, lenB));
                }

                pi = ci;
                pj = cj;

                ci = cj;
            }

            int lenA = pj - pi, lenB = cj - ci;
            ans = max(ans, max(lenA, lenB)/2);
            cj++;
        }
        if(ci == pj) {
            int lenA = pj - pi, lenB = cj - ci;
            ans = max(ans, min(lenA, lenB));
        }
        int lenA = pj - pi, lenB = cj - ci;
        ans = max(ans, max(lenA, lenB)/2);

        return ans;
    }
};