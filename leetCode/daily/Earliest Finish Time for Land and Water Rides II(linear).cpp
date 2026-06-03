const int INF = 1e9;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto earliestFinishTimeInOreder = [] (vector<int>& firstStart, vector<int>& firstDuration, vector<int>& secondStart, vector<int>& secondDuration) {
            int n = firstStart.size(), m = secondStart.size();
            int earliestFinish = INF, minFirstEnd = INF;
            for(int i = 0; i < n; i++) minFirstEnd = min(minFirstEnd, firstStart[i] + firstDuration[i]);
            for(int i = 0; i < m; i++) earliestFinish = min(earliestFinish, max(minFirstEnd, secondStart[i]) + secondDuration[i]);
            return earliestFinish;
        };
        return min(earliestFinishTimeInOreder(waterStartTime, waterDuration, landStartTime, landDuration), earliestFinishTimeInOreder(landStartTime, landDuration, waterStartTime, waterDuration));
    }
};