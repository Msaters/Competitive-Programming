const long long INF = 1e15;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        // implemented with Editorial 
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> flatened_factory;
        for(auto f : factory) {
            for(int i = 0; i < f[1]; i++) flatened_factory.push_back(f[0]);
        }

        vector<vector<long long>> cache(robot.size(), vector<long long>(flatened_factory.size(), -1));
        return minimumDistance(0, 0, robot, flatened_factory, cache);
    }

    long long minimumDistance(int robotIdx, int factoryIdx, vector<int>& robot, vector<int>& flatened_factory, vector<vector<long long>>& cache) {
        if(robotIdx == robot.size()) return 0;
        if(factoryIdx == flatened_factory.size()) return INF;
     if (cache[robotIdx][factoryIdx] != -1) return cache[robotIdx][factoryIdx];
        long long assign = abs(robot[robotIdx] - flatened_factory[factoryIdx]) +
                           minimumDistance(robotIdx + 1, factoryIdx + 1,
                                                robot, flatened_factory, cache);
        long long skip = minimumDistance(robotIdx, factoryIdx + 1, robot,
                                              flatened_factory, cache);

        return cache[robotIdx][factoryIdx] =
                   min(assign, skip);
    }
};