#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int maxJump = 20;
int dist[N];
int up[N][maxJump];
int InTime[N];
int OutTime[N];
vector<int> G[N];

bool isAncestor(int a, int b, int p) {
    return (InTime[p] <= InTime[a]) && (OutTime[p] >= InTime[a]) && (InTime[p] <= InTime[b]) && (OutTime[p] >= InTime[b]);
}

int getLCA(int a, int b) {
    if(isAncestor(a, b, a)) return a;
    if(isAncestor(a, b, b)) return b;
    
    for(int currJump = maxJump-1; currJump >= 0; currJump--) {
        if(!isAncestor(a, b, up[a][currJump])) {
            a = up[a][currJump];
        }
    }
    
    return up[a][0];
}


int t = 1;
void preprocess(int v, int p) {
    InTime[v] = t; t++;
    dist[v] = dist[p] + 1;
    up[v][0] = p;
    for(int currJump = 1; currJump < maxJump; currJump++) {
        up[v][currJump] = up[up[v][currJump - 1]][currJump - 1];
    }
    
    for(int w : G[v]) {
        if(w != p) {
            preprocess(w, v);
        }
    }
    OutTime[v] = t; t++;
}



int main() {
	int n, q; cin >> n >> q;
	for(int i = 0; i < n-1; i++) {
	    int a, b; cin >> a >> b;
	    G[a].push_back(b);
	    G[b].push_back(a);
	}
	
	InTime[0] = -1e8;
	OutTime[0] = 1e8;
    preprocess(1, 0);
    
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        int lca = getLCA(a, b);
        //printf("a: %d, dist[a] : %d, b: %d, dist[b]: %d,lca: %d, dist[lca]: %d \n", a, dist[a], b, dist[b], lca, dist[lca]);
        cout << dist[a] + dist[b] - 2 * dist[lca] << "\n"; 
    }
}
