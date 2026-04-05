class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for(int i = 0; i < ranges.size(); i++) {
            if(left >= ranges[i][0] && left <= ranges[i][1]) {
                left = ranges[i][1] + 1;
            }
        }
        return left > right;
    }
};