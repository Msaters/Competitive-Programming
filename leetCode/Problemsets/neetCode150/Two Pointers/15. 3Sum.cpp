class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<tuple<int, int, int>> s;
        for(int k = 0; k < nums.size(); k++) {
            int l = k - 1, r = k + 1;
            while(l >= 0 && r < nums.size()) {
                if(nums[l] + nums[k] + nums[r] == 0) { 
                    s.insert({nums[l], nums[k], nums[r]});
                    r++;
                    continue;
                }
                if(nums[l] + nums[k] + nums[r] > 0) l--;
                else r++;
            }
        }

        vector<vector<int>> res;
        for(auto t : s) {
            res.push_back({get<0>(t), get<1>(t), get<2>(t)});
        }
        return res;
    }
};