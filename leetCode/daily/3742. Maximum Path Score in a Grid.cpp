const int max_N = 207;
const int max_k = 1e3 + 7;
int dp[max_N][max_N][max_k];
const int INF = 1e9;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                for(int l = 0; l <= k; l++) {
                    dp[i][j][l] = -INF;
                }
            }
        }

        int cost = grid[0][0] == 0 ? 0 : 1;
        dp[1][1][cost] = grid[0][0];

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int curr = grid[i-1][j-1];
                cost = grid[i-1][j-1] == 0 ? 0 : 1;

                if(!(i == 1 && j == 1)) {
                    for(int l = cost; l <= k; l++) {
                        dp[i][j][l] = max(dp[i - 1][j][l - cost], dp[i][j - 1][l - cost]) + curr;
                    }
                }
            }
        }

        int res = -INF;
        for(int l = 0; l <= k; l++) {
            res = max(res, dp[m][n][l]);
        }

        if(res < 0) return -1;
        return res;
    }

};