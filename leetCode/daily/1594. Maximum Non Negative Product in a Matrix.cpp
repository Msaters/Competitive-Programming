class Solution {
public:
    static const int N = 16;
    pair<long, long> dp[N][N];
    int mod = 1e9 + 7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp[1][1].first = grid[0][0];
        dp[1][1].second = grid[0][0];
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int actualElement = grid[i-1][j-1];
                if(i == 1 && j > 1) {
                    dp[i][j].first = min(actualElement * dp[i][j-1].first, actualElement * dp[i][j-1].second);
                    dp[i][j].second = max(actualElement * dp[i][j-1].first, actualElement * dp[i][j-1].second);
                }

                if(i > 1 && j == 1) {
                    dp[i][j].first = min(actualElement * dp[i-1][j].first, actualElement * dp[i-1][j].second);
                    dp[i][j].second = max(actualElement * dp[i-1][j].first, actualElement * dp[i-1][j].second);
                }

                if(i > 1 && j > 1) {
                    dp[i][j].first = min(min(actualElement * dp[i-1][j].first, actualElement * dp[i-1][j].second),
                    min(actualElement * dp[i][j-1].first, actualElement * dp[i][j-1].second));
                    dp[i][j].second = max(max(actualElement * dp[i-1][j].first, actualElement * dp[i-1][j].second),
                    max(actualElement * dp[i][j-1].first, actualElement * dp[i][j-1].second));
                }
            }
        }

        if(dp[m][n].second < 0) {
            return -1;
        }
        return dp[m][n].second % mod;
    }
};