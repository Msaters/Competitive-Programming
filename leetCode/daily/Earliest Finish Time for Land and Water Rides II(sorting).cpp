const int INF = 1e9;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<int> landTimeEnd = {INF};
        vector<pair<int, int>> landing = {{INF, INF}};
        vector<int> waterTimeEnd = {INF};
        vector<pair<int, int>> watering = {{INF, INF}};
        for(int i = 0; i < n; i++) {
            landTimeEnd.push_back(landStartTime[i] + landDuration[i]);
            landing.push_back({landStartTime[i], landDuration[i]});
        }

        for(int i = 0; i < m; i++) {
            waterTimeEnd.push_back(waterStartTime[i] + waterDuration[i]);
            watering.push_back({waterStartTime[i], waterDuration[i]});
        }

        sort(landTimeEnd.begin(), landTimeEnd.end());
        sort(landing.begin(), landing.end());
        sort(waterTimeEnd.begin(), waterTimeEnd.end());
        sort(watering.begin(), watering.end());
        int earliestFinishTimeResult = INF;

        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j < m && watering[j].first <= landTimeEnd[i+1]) {
                earliestFinishTimeResult = min(earliestFinishTimeResult, max(landTimeEnd[i], watering[j].first) + watering[j].second);
                j++;
            }
        }

        j++;
        for(j; j < m; j++) earliestFinishTimeResult = min(earliestFinishTimeResult, max(landTimeEnd[n-1], watering[j].first) + watering[j].second);

        j = 0;
        for(int i = 0; i < m; i++) {
            while(j < n && landing[j].first <= waterTimeEnd[i+1]) {
                earliestFinishTimeResult = min(earliestFinishTimeResult, max(waterTimeEnd[i], landing[j].first) + landing[j].second);
                j++;
            }
        }

        j++;
        for(j; j < n; j++) earliestFinishTimeResult = min(earliestFinishTimeResult, max(waterTimeEnd[m-1], landing[j].first) + landing[j].second);

        return earliestFinishTimeResult;
    }
};