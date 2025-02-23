
//solved

#include <bits/stdc++.h>
using namespace std;
const int NSIZ = 59;
char S[NSIZ][NSIZ];
char T[NSIZ][NSIZ];

bool isInXY(int x, int y, int m, int n) {
    if(m - 1 + x >= n || m - 1 + y >= n) return false;
    bool wasMiss = false;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(T[i][j] != S[x + i][y + j]) wasMiss = true;
        }
    }
    
    return !wasMiss;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> T[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isInXY(i, j, m, n)) {
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "didn't found";
    return 0;
}