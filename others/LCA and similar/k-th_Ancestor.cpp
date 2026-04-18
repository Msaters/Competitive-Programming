#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int maxJump = 20;
long long dist[N][maxJump];

void buildJumpTable(int n) {
    for(int i = 1; i < maxJump; i++) {
        for(int v = 1; v <= n; v++) {
            dist[v][i] = dist[dist[v][i-1]][i-1];
        }
    }
}

int getKthParent(int k, int i) {
    int j = 0;
    
    while(k) {
        if(k%2) {
            i = dist[i][j];
        }
        
        j++;
        k /= 2;
    }
    
    return i;
}

int main() {
	int n, q; cin >> n >> q;
	
	for(int i = 2; i <= n; i++) {
	    int a; cin >> a;
	    dist[i][0] = a;
	}
	
	buildJumpTable(n);
	
	
	for(int i = 0; i < q; i++) {
	    int v, k; cin >> v >> k;
	    int distK = getKthParent(k, v);
	    if(distK) {
	        cout << distK << "\n";
	    } else {
	        cout << -1 << "\n";
	    }
	}
	

}
