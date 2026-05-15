#include <bits/stdc++.h>
using namespace std;
const int H = 1e6 + 7;

int dp[H];
int nextDp[H];

int findMin(int max_h) {
    for(int i = 0; i <= max_h; i++) {
        if(dp[i] > i) return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    if (!(cin >> n)) return 0;
    
    memset(dp, -1, sizeof(dp));
    memset(nextDp, -1, sizeof(nextDp));
    
    dp[0] = 0;
    nextDp[0] = 0;
    
    int current_max_h = 0;
    
    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        
        for(int h = 0; h <= current_max_h; h++) {
            if(dp[h] == -1) continue; 
            
            int diff1 = h + a;
            if (diff1 < H) {
                nextDp[diff1] = max(nextDp[diff1], dp[h] + a);
            }
            
            int diff2 = abs(h - a); 
            int height2 = max(dp[h], dp[h] - h + a);
            if (diff2 < H) {
                nextDp[diff2] = max(nextDp[diff2], height2);
            }
        }
        
        current_max_h += a;
        if (current_max_h >= H) current_max_h = H - 1;
        
        for(int h = 0; h <= current_max_h; h++) {
            dp[h] = nextDp[h];
        }
    }
    
    if(dp[0] == 0) {
        printf("NIE\n%d", findMin(current_max_h));
    } else {
        printf("TAK\n%d", dp[0]);
    }
    
    return 0;
}