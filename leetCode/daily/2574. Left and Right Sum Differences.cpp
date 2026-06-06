const int max_n = 1e3 + 7;
int prefix[max_n];
int sufix[max_n];

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        prefix[0] = 0;
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        vector<int> ans;
        sufix[n+1] = 0;
        for(int i = n; i > 0; i--) {
            sufix[i] = sufix[i + 1] + nums[i-1];
            ans.push_back(abs(sufix[i] - prefix[i]));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};