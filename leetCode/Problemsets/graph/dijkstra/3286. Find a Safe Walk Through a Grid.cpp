#define trio tuple<int, int, int>

const int max_n = 57;
int minDemage[max_n][max_n];
bool vis[max_n][max_n];

struct compare {
    bool operator() (const trio& a, const trio& b) const {
        return get<0>(a) > get<0>(b);
    }
};

class Solution {        
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // dijkstra
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = false;
                minDemage[i][j] = 0;
            }
        }

        priority_queue<trio, vector<trio>, compare> pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            if(!vis[i][j]) {
                vis[i][j] = true;
                minDemage[i][j] = d;

                if(i - 1 >= 0 && !vis[i - 1][j]) {
                    pq.push({d + grid[i-1][j], i - 1, j});
                }
                if(j - 1 >= 0 && !vis[i][j - 1]) {
                    pq.push({d + grid[i][j - 1], i, j - 1});
                }
                if(i + 1 < n && !vis[i+1][j]) {
                    pq.push({d + grid[i+1][j], i+1, j});
                }
                if(j + 1 < m && !vis[i][j+1]) {
                    pq.push({d + grid[i][j+1], i, j+1});
                }
            }
        }

        return health > minDemage[n-1][m-1];
    }
};