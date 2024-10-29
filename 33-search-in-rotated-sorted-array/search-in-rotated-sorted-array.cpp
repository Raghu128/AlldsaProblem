class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        if(end == 0) {
            if(target == nums[end]) return 0;
            return -1;
        }

        if(end == 1) {
            if(target == nums[end]) return end;
            if(target == nums[start]) return start;

            return -1;
        }

        while(start <= end) {
            int mid = (end+start)/2;

            if(nums[mid] == target) return mid;
            if(nums[start] <= nums[mid]) {
                if(nums[start] <= target && target < nums[mid]) end = mid-1;
                else start = mid+1;
            }
            else {
                if(nums[mid] < target && target <= nums[end]) start = mid+1;
                else end = mid-1;
            }
        }

        return -1;
    }
};