class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliestHour = 1e9;
        for(int i = 0; i < landStartTime.size(); i++) {
            for(int j = 0; j < waterStartTime.size(); j++) {
                if(landStartTime[i] < waterStartTime[j]) {
                    earliestHour = min(earliestHour, max(waterStartTime[j], landStartTime[i] + landDuration[i]) + waterDuration[j]);
                } else {
                    earliestHour = min(earliestHour, max(landStartTime[i], waterStartTime[j] + waterDuration[j]) + landDuration[i]);
                }
            }
        }

        return earliestHour;
    }
};