#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int N = 2000 + 7;
char T[N][N];
bool vis[N][N];
char blank = 'A';

bool isConnectedUpwards(char Up, char D) {
    //cout << Up << " " << D << " upwards check\n";
    switch(Up){
        case 'A': 
            return false;
            
        case 'B':
            return (D == 'C' || D == 'D' || D == 'F');
            
        case 'C':
            return false;
        
        case 'D':
            return false;
            
        case 'E':
            return (D == 'C' || D == 'D' || D == 'F');
        
        case 'F':
            return (D == 'C' || D == 'D' || D == 'F');
            
        default:
            return false;
    }
}

bool isConnectedLeft(char L, char R) {
    //cout << L << " " << R << " left check\n";
    switch(L){
        case 'A': 
            return false;
            
        case 'B':
            return false;
            
        case 'C':
            return false;
        
        case 'D':
            return (R == 'B' || R == 'C' || R == 'F');
            
        case 'E':
            return (R == 'B' || R == 'C' || R == 'F');
        
        case 'F':
            return (R == 'B' || R == 'C' || R == 'F');
            
        default:
            return false;
    }
}

void initialize(int n, int m) {
    for(int i = 0; i <= n+1; i++) {
        if(i == 0 || i == n+1)
            for(int j = 0; j <= m+1; j++) {
                T[i][j] = blank;
            }
        T[i][0] = blank;
        T[i][m+1] = blank;
    }
}

void bfs(int s_i, int s_j) {
    queue<pair<int, int>> Q;
    Q.push({s_i, s_j});
    vis[s_i][s_j] = true;
    
    while(!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop();
        
        // lewo
        if(isConnectedLeft(T[i][j-1], T[i][j])) {
            if(!vis[i][j-1]) {
                vis[i][j-1] = true;
                Q.push({i, j-1});
            }
        }
        
        // prawo
        if(isConnectedLeft(T[i][j], T[i][j+1])) {
            if(!vis[i][j+1]) {
                vis[i][j+1] = true;
                Q.push({i, j+1});
            }
        }
        
        // gora
        if(isConnectedUpwards(T[i-1][j], T[i][j])) {
            if(!vis[i-1][j]) {
                vis[i-1][j] = true;
                Q.push({i-1, j});
            }
        }
        
        // dol
        if(isConnectedUpwards(T[i][j], T[i+1][j])) {
            if(!vis[i+1][j]) {
                vis[i+1][j] = true;
                Q.push({i+1, j});
            }
        }
        
    }
}

int main() {
    int n, m;
    int res = 0;
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        scanf("%s", &T[i][1]);
    }
    
    initialize(n, m);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!vis[i][j] && T[i][j] != blank) {
                res++;
                //cout << "res: " << res << "\n";
                bfs(i, j);
            }
        }
    }
    cout << res;

}