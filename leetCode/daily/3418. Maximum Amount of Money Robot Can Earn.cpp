const int N = 507;
const int minINF = -1e9;
int dp[N][N][3];
int m, n;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int currCoin = coins[i-1][j-1];
                if(i == 1 || j == 1) {
                    if(i == 1 && j == 1) {
                        dp[i][j][0] = currCoin;
                    } else {
                        if(i == 1) {
                            dp[i][j][0] = dp[i][j - 1][0] + currCoin;
                            dp[i][j][1] = max(dp[i][j-1][1] + currCoin, dp[i][j-1][0]);
                            dp[i][j][2] = max(dp[i][j-1][2] + currCoin, dp[i][j-1][1]);
                        }

                        if(j == 1) {
                            dp[i][j][0] = dp[i-1][j][0] + currCoin;
                            dp[i][j][1] = max(dp[i-1][j][1] + currCoin, dp[i - 1][j][0]);
                            dp[i][j][2] = max(dp[i-1][j][2] + currCoin, dp[i - 1][j][1]);
                        }
                    }
                } else {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + currCoin;
                    dp[i][j][1] = max(max(dp[i-1][j][1], dp[i][j-1][1]) + currCoin,
                    max(dp[i-1][j][0], dp[i][j-1][0]));
                    dp[i][j][2] = max(max(dp[i-1][j][2], dp[i][j-1][2]) + currCoin,
                    max(dp[i-1][j][1], dp[i][j-1][1]));
                }
            }
        }

        int result = minINF;
        for(int k = 0; k < 3; k++) {
            result = max(result, dp[m][n][k]);
        }
        return result;
    }
};