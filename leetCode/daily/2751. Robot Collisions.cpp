class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = healths.size();
        stack<pair<int, int>> healthsStack;
        vector<pair<int, int>> result;
        vector<pair<int, int>> newIndexes;

        for(int i = 0; i < n; i++) {
            newIndexes.push_back({positions[i], i});
        }
        sort(newIndexes.begin(), newIndexes.end());

        for(int i = 0; i < n; i++) {
            int newI = newIndexes[i].second;
            if(directions[newI] == 'R') {
                healthsStack.push({newI, healths[newI]});
            } else {
                bool died = false;
                while(!healthsStack.empty() && !died) {
                    auto [j, healthj] = healthsStack.top();
                    //printf("j: %d, healthj: %d, i: %d, healths[i]: %d\n", j, healthj, i,  healths[i]);
                    healthsStack.pop();
                    if(healths[newI] == healthj) {
                        died = true;
                    }

                    if(healths[newI] > healthj) {
                        healths[newI]--;
                    }

                    if(healths[newI] < healthj) {
                        died = true;
                        healthsStack.push({j, healthj - 1});
                    }
                }
                
                if(!died) {
                    result.push_back({newI, healths[newI]});
                }
            }
        }

        while(!healthsStack.empty()) {
            auto [i, health] = healthsStack.top();
            healthsStack.pop();
            result.push_back({i, health});
        }

        sort(result.begin(), result.end());
        vector<int> resultVec;
        for(auto [i, health] : result) {
            resultVec.push_back(health);
        }
        return resultVec;
    }
};