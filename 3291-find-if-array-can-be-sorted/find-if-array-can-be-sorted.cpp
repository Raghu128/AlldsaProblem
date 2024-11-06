class Solution {
public:
    int cntSetBits(int n) {
        int cnt = 0;
        while(n) {
            if(n&1) cnt++;
            n = n >> 1;
        }

        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, cnt = 0, prev = 0;

        for(int i = 0; i < n; i++) {
            int setBit = cntSetBits(nums[i]);
    
            if(cnt != setBit) {
                prev = maxi;
                if(prev > nums[i]) return false;
                cnt = setBit;
            }
            else {
                if(prev > nums[i]) return false;
            }
            maxi = max(maxi, nums[i]);
        }

        return true;
    }
};