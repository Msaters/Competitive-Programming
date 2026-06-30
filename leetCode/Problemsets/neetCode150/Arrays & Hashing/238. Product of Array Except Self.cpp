const int N = 1e5 + 7;
uint suffix[N];

class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        suffix[n] = 1;
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }        

        uint pref = 1;
        for(int i = 0; i < n; i++) {
            uint num = nums[i];
            nums[i] = pref * suffix[i+1];
            pref *= num;
        }

        return nums;
    }
};