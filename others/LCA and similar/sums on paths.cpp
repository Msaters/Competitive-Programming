#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> G[N];
int in[N];
int out[N];
long long firstValues[N];
long long valDist[N];
const int base = 262144;

struct node {
  long long change;
  int left, right;
};
node segTree[base * 2];

node composeNodes(node& a, node& b) {
    return {a.change + b.change, a.left, b.right};
}

int t = 0;
void preprocesDfs(int v, int p) {
    in[v] = t;
    valDist[v] = valDist[p] + firstValues[v];
    t++;
    
    for(int w : G[v]) {
        if(w != p) {
            preprocesDfs(w, v);
        }
    }
    
    out[v] = t - 1;
}

long long getTraceValue(int v) {
    long long res = valDist[v];
    v = in[v] + base;
    
    while(v) {
        res += segTree[v].change;
        v >>= 1;
    }
    return res;
}

void setChangeValue(int l, int r, int v, int newChange) {
    if(segTree[v].left >= l && segTree[v].right <= r) {
        //printf("l: %d, r: %d, v: %d, newChange: %d\n", l, r, v, newChange);
        segTree[v].change += newChange;
        return;
    }
    if(segTree[v].left > r || segTree[v].right < l) return;
    setChangeValue(l, r, 2*v, newChange); setChangeValue(l, r, 2*v + 1, newChange);
}

int main() {
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> firstValues[i];
	for(int i = 0; i < n - 1; i++) {
	    int a, b; 
	    cin >> a >> b;
	    G[a].push_back(b);
	    G[b].push_back(a);
	}
	
	for(int i = base; i < base*2; i++) {
	    segTree[i].left = i - base;
	    segTree[i].right = i - base;
	}
	preprocesDfs(1, 0);
	for(int i = base - 1; i > 0; i--) {
	    segTree[i] = composeNodes(segTree[i*2], segTree[i*2 + 1]);
	}
	
	for(int i = 0; i < q; i++) {
	    int a; cin >> a;
	    if(a == 1) {
	        int v; long long val; cin >> v >> val;
	        setChangeValue(in[v], out[v], 1, val - firstValues[v]);
	        firstValues[v] = val;
	    } else {
	        int v; cin >> v;
	        cout << getTraceValue(v) << "\n";
	    }
	}
	
}
