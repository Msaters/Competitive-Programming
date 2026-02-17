#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second 

const int INF = 1e7;

const int N = 2007;
int dp[N][N];
char matrix[N][N];
bool canTakeFrom[N][N];

int main() {
    int n, k; cin >> n >> k;
    int m = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = INF;
        dp[0][i] = INF;
    }
    
    dp[1][0] = 0;
    canTakeFrom[1][1] = true;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] += matrix[i][j] == 'a' ? 0 : 1;
            if(dp[i][j] <= k) {
                canTakeFrom[i+1][j] = true;
                canTakeFrom[i][j+1] = true;
                m = max(m, i+j-1);
                //cout << i << " " << j << " " << i+j-1 << endl;
            }
        }
    }
    
    string ans(m, 'a');
    for(int i = m + 1; i < 2*n; i++) {
        char minChar = 'z'; 
        //cout << "i: " << i << endl;
        for(int j = 1; j <= n; j++) {
            int r = i-j+1;
            if(r > 0 && r <= n && canTakeFrom[j][r])
                minChar = min(minChar, matrix[j][r]);
                //cout << matrix[j][r] << " j: " << j << " i-j: " << r << endl;
        }
        
        for(int j = 1; j <= n; j++) {
            int r = i-j+1;
            if(r > 0 && r <= n && canTakeFrom[j][r] && matrix[j][r] == minChar) {
                canTakeFrom[j+1][r] = true;
                canTakeFrom[j][r+1] = true;
            }
        }
        
        ans += minChar;
        //cout << ans << " " << minChar << endl;
    }
    
    cout << ans << endl;
    
}