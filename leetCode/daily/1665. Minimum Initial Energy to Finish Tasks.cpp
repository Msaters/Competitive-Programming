class Solution {
public:
    bool finishable(long long energy, vector<vector<int>>& tasks) {
        //printf("energy: %d\n", energy);
        for(int i = 0; i < tasks.size(); i++) {
            int act = tasks[i][0], mini = tasks[i][1];
            if(energy < mini) {
                //printf("FALSE e: %d, mini: %d, act: %d\n", energy, mini, act);
                return false;
            } 
            energy -= act;
            //printf("e: %d, mini: %d, act: %d\n", energy, mini, act);
        }
        return energy >= 0;
    }

    long long binary_search(long long l, long long r, vector<vector<int>>& tasks) {
        while(l < r) {
            long long mid = (l+r)/2;
            if(finishable(mid, tasks)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        return binary_search(0, static_cast<long long>(2e9), tasks);
    }
};