
const int max_n = 407;
int dist[max_n][max_n];
int maxSafeness[max_n][max_n];
bool vis[max_n][max_n];
const int INF = 1e9;

class Solution {
private:
    void dijkstra(int n) {
        priority_queue<tuple<int, int, int>> pq;
        pq.push({dist[0][0], 0, 0});
        //printf("dikstra\n");
        while(!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            //printf("i: %d, j: %d, d: %d\n", i, j, d);
            if(!vis[i][j]) {
                vis[i][j] = true;
                maxSafeness[i][j] = min(d, dist[i][j]);
                //printf("maxSageness: %d\n", maxSafeness[i][j]);
                if(i == n -1 && j == i) return;

                if(i - 1 >= 0 && !vis[i-1][j]) {
                    pq.push({maxSafeness[i][j], i-1, j});
                } 
                if(j - 1 >= 0 && !vis[i][j - 1]) {
                    pq.push({maxSafeness[i][j], i, j - 1});
                } 
                if(i + 1 < n && !vis[i+1][j]) {
                    pq.push({maxSafeness[i][j], i+1, j});
                }
                if(j + 1 < n && !vis[i][j + 1]) {
                    pq.push({maxSafeness[i][j], i, j + 1});
                }
            }
        }
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> thiefs;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = INF;
                vis[i][j] = false;
                if(grid[i][j] == 1) {
                    thiefs.push({i, j, 0});
                    vis[i][j] = true;
                }
            }
        }

        while(!thiefs.empty()) {
            auto [i, j, d] = thiefs.front(); thiefs.pop();
            //printf("i: %d, j: %d, d: %d\n", i, j, d);
            dist[i][j] = d;
            if(i - 1 >= 0 && !vis[i-1][j]) {
                vis[i-1][j] = true;
                thiefs.push({i-1, j, d + 1});
            } 
            if(j - 1 >= 0 && !vis[i][j - 1]) {
                vis[i][j -  1] = true;
                thiefs.push({i, j - 1, d + 1});
            } 
            if(i + 1 < n && !vis[i+1][j]) {
                vis[i+1][j] = true;
                thiefs.push({i+1, j, d + 1});
            }
            if(j + 1 < n && !vis[i][j + 1]) {
                vis[i][j + 1] = true;
                thiefs.push({i, j + 1, d + 1});
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vis[i][j] = false;
            }
        }

        dijkstra(n);
        return maxSafeness[n-1][n-1];
    }
};