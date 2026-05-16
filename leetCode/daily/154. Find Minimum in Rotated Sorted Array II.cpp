class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0; int right = nums.size() - 1;
        if(nums[left] < nums[right]) return nums[left];
        while(left < right - 1) {
            int mid = (left + right + 1) / 2;
            if(nums[mid] > nums[left]) left = mid;
            if(left + 1 < nums.size() && nums[left] == nums[left + 1]) left++;
            if(nums[mid] < nums[right]) right = mid;
            if(right - 1 > 0 && nums[right] == nums[right - 1]) right--;
        }
        return nums[right];
    }
};