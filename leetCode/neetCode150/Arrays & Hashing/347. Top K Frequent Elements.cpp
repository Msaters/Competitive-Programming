const int base = 1e4 + 5;
int T[base*2];

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int num : nums) {
            T[num + base]++;
        } 

        vector<pair<int, int>> frequncies;
        for(int num : nums) {
            if(T[num + base]) {
                frequncies.push_back({T[num + base], num});
            }
            T[num + base] = 0;
        }

        sort(frequncies.begin(), frequncies.end(), greater<pair<int, int>>());
        vector<int> topKfreq;
        for(int i = 0; i < k; i++) {
            topKfreq.push_back(frequncies[i].second);
        }
        return topKfreq;
    }
};