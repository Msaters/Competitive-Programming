class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int previousNum = nums[0], currSize = 1, longest = 1;
        for(int num : nums) {
            if(num == previousNum) continue;
            if(num != previousNum + 1) {
                currSize = 0;
            } 
            previousNum = num;
            currSize++;
            longest = max(longest, currSize);
        }
        return longest;
    }
};