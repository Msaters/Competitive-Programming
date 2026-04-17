const int N = 1e6 + 7;
int lastSeen[N];
const int INF = 1e8;

#define left first 
#define right second 

pair<int, int> closests[N]; 

class Solution {
private:
    int distance(int x, int y, int n) {
        if(x == INF || y == INF) return -1;
        return min(abs(y-x), n - abs(y-x));
}

public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        for(int i = 0; i < N; i++) {
            lastSeen[i] = INF;
            closests[i] = {INF, INF};
        }

        for(int i = 0; i < nums.size(); i++) {
            if(lastSeen[nums[i]] == INF) {
                lastSeen[nums[i]] = i;
            } else {
                closests[lastSeen[nums[i]]].right = i;
                closests[i].left = lastSeen[nums[i]];
                lastSeen[nums[i]] = i;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(lastSeen[nums[i]] != i && closests[i].left == INF) {
                closests[i].left = lastSeen[nums[i]];
                closests[lastSeen[nums[i]]].right = i;
            }
        }

        vector<int> result;
        for(int i = 0; i < queries.size(); i++) {
            int leftDist = distance(queries[i], closests[queries[i]].left, nums.size());
            int rightDist = distance(queries[i], closests[queries[i]].right, nums.size());
            result.push_back(min(leftDist, rightDist));
        }
        return result;
    }
};