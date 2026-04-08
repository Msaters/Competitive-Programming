int mod = 1e9 + 7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(auto q : queries) {
            long l = q[0], r = q[1], k = q[2], v = q[3];
            for(l; l <= r; l += k) {
                long value = ((long) nums[l] * v) % mod;
                nums[l] = (int) value;
            }
        }

        long res = nums[0];
        for(int i = 1; i < n; i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};