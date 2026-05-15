class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0; int right = nums.size() - 1;
        if(nums[left] < nums[right]) return nums[left];
        while(left < right - 1) {
            int mid = (left + right + 1) / 2;
            if(nums[mid] < nums[right]) {
                right = mid;
            }
            if(nums[mid] > nums[left]) {
                left = mid;
            }
        }

        return nums[right];
    }
};