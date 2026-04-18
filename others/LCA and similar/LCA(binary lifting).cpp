#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int maxJump = 20;
int dist[N][maxJump];
int InTime[N];
int OutTime[N];
vector<int> G[N];


void buildJumpTable(int n) {
    for(int i = 1; i < maxJump; i++) {
        for(int v = 1; v <= n; v++) {
            dist[v][i] = dist[dist[v][i-1]][i-1];
        }
    }
}

bool isAncestor(int a, int b, int p) {
    return (InTime[p] <= InTime[a]) && (OutTime[p] >= InTime[a]) && (InTime[p] <= InTime[b]) && (OutTime[p] >= InTime[b]);
}

int getLCA(int a, int b) {
    if(isAncestor(a, b, a)) return a;
    if(isAncestor(a, b, b)) return b;
    
    //printf("a: %d, b: %d, v: %d\n", a, b, v);
    for(int currJump = maxJump-1; currJump >= 0; currJump--) {
        if(!isAncestor(a, b, dist[a][currJump])) {
            a = dist[a][currJump];
            //printf("a: %d, b: %d, v: %d\n", a, b, v);
        }
    }
    
    return dist[a][0];
}

int buildInOutTimers(int v, int t, int p) {
    InTime[0] = -1e8;
    OutTime[0] = 1e8;
    
    InTime[v] = t; t++;
    for(int w : G[v]) {
        if(w != p) {
            t = buildInOutTimers(w, t, v);
        }
    }
    OutTime[v] = t; t++;
    return t;
}

int main() {
	int n, q; cin >> n >> q;
	
	for(int i = 2; i <= n; i++) {
	    int a; cin >> a;
	    dist[i][0] = a;
	    G[i].push_back(a);
	    G[a].push_back(i);
	}
	
	buildInOutTimers(1, 1, 0);
	buildJumpTable(n);
	
	
	for(int i = 0; i < q; i++) {
	    int a, b; cin >> a >> b;
	    cout << getLCA(a, b) << "\n";
	}
	

}
