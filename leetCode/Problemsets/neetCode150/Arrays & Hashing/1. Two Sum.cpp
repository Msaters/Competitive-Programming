class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numsWithIndexes(n, {0, 0});
        for(int i = 0; i < n; i++) numsWithIndexes[i] = {nums[i], i};
        sort(numsWithIndexes.begin(), numsWithIndexes.end());

        int l = 0, r = nums.size() - 1;
        while(l < r) {
            if(numsWithIndexes[l].first + numsWithIndexes[r].first == target) 
                return {numsWithIndexes[l].second, numsWithIndexes[r].second};
            if(numsWithIndexes[l].first + numsWithIndexes[r].first > target) r--;
            else l++;
        }
        return {-1, -1};
    }
};