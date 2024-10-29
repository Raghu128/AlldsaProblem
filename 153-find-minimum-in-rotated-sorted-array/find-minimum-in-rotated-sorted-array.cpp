class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        if(start == end) return nums[end];
        if(start + 1 == end) return min(nums[start], nums[end]);

        while(start < end) {
            int mid = (end + start)/2;
            if(nums[start] <= nums[mid]) {
                if(nums[start] < nums[end]) end = mid-1;
                else {
                    if(nums[mid] > nums[end]) start = mid+1;
                    else end = mid;
                }
            }
            else {
                if(nums[start] < nums[end]) end = mid-1;
                else {
                    if(nums[mid] > nums[end]) start = mid+1;
                    else end = mid;
                }
            }
        }

        return nums[start];
    }
};