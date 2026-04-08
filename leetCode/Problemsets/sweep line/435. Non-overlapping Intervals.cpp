class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<tuple<int, int, int, int>> Entries;
        map<pair<int, int>, bool> poped;
        for(auto point : intervals) {
            Entries.push_back({point[0], 1, point[0], point[1]});
            Entries.push_back({point[1], -1, point[0], point[1]});
        }

        sort(Entries.begin(), Entries.end());
        stack<pair<int, int>> S;
        int result = 0; int currBallons = 0;
        for(auto entry : Entries) {
            auto [c, v, i, j] = entry;
            //printf("[%d %d %d %d]: %d  ", c, i, j, v, poped[{i, j}]);
            if(!poped[{i, j}] && currBallons > 0 && v == -1) {
                result += currBallons - 1;
                currBallons = 0;
                while(!S.empty()) {
                    auto [l, r] = S.top();
                    S.pop();
                    poped[{l, r}] = true;
                }
            }

            if(v == 1) {
                currBallons++;
                S.push({i, j});
            }
        }
        return result;
    }
};