class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();

        if(n%2 == 0 && m%2 == 0) return 0;
        if(m%2) for(auto i : nums1) ans ^= i;

        if(n%2) {
            for(auto i : nums2) ans ^= i;
        }


        return ans;
    }
};