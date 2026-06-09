class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxV = *max_element(nums.begin(), nums.end()), minV = *min_element(nums.begin(), nums.end());
        return static_cast<long long>(k * (maxV - minV));
    }
};