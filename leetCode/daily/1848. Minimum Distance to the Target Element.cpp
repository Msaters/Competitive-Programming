class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = 1e9;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                result = min(result, abs(i - start));
            }
        }

        return result;
    }
};