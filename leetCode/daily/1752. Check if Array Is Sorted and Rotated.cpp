class Solution {
public:
    bool check(vector<int>& nums) {
        int leftBoundary = nums[0];
        bool changedOrder = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                if(changedOrder) return false;
                changedOrder = true;
            }
            if(changedOrder && nums[i] > leftBoundary) return false;
        }

        return true;
    }
};