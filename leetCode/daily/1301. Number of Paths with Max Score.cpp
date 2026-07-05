const int max_n = 107;
#define ll long long
pair<int, int> dp[2][max_n]; // maxPath, count
const int mod = 1e9 + 7;
int cost, maxVal, p, next_p;
ll paths;
char c;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        for(int i = 0; i <= n; i++) {
           dp[0][i] = {0, 0};
           dp[1][i] = {0, 0};
        }
        dp[(n-1)%2][n-1] = {0, 1};

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                c = board[i][j];
                if(i == n-1 && j == n-1) continue;
                if(c != 'X') { 
                    p = i%2;
                    next_p = (i+1)%2;
                    cost = (c == 'E' || c == 'S') ? 0 : c - '0';
                    maxVal = max(max(dp[p][j + 1].first, dp[next_p][j + 1].first), dp[next_p][j].first);
                    paths = 0;
                    if(dp[p][j+1].first == maxVal) paths += dp[p][j+1].second; 
                    if(dp[next_p][j+1].first == maxVal) paths += dp[next_p][j+1].second; 
                    if(dp[next_p][j].first == maxVal) paths += dp[next_p][j].second; 
                    dp[p][j] = {maxVal + cost, paths % mod};
                } else {
                    dp[i%2][j] = {0, 0};
                }
            }
        }

        if(!dp[0][0].second) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};