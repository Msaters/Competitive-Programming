class Solution {
    int searchInSubArr(vector<int>& nums, int l, int r, int target) {
        int index = std::distance(nums.begin(), std::lower_bound(nums.begin() + l, nums.begin() + r, target));
        return nums[index] == target ? index : -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        int l = 0, r = n - 1;    
        if(nums[0] < nums[r]) return searchInSubArr(nums, 0, r, target);
        while(l < r - 1) {
            int m = (l + r + 1) / 2;
            if(nums[m] > nums[l]) l = m;
            if(nums[m] < nums[r]) r = m; 
        }
        
        return max(searchInSubArr(nums, 0, l, target), searchInSubArr(nums, r, n - 1, target));
    }
};