#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> G[N];
int in[N];
int out[N];
long long val[N];

const int base = 262144;

struct node {
  long long suma;
  int left, right;
};
node segTree[base * 2];

node composeNodes(node& a, node& b) {
    return {a.suma + b.suma, a.left, b.right};
}

int t = 0;
void preprocesDfs(int v, int p) {
    in[v] = t;
    segTree[base + t].suma = val[v-1];
    t++;
    
    for(int w : G[v]) {
        if(w != p) {
            preprocesDfs(w, v);
        }
    }
    
    out[v] = t - 1;
}

void addValue(int v, long long val) {
    v += base;
    //printf("v: %d, segTree[v].suma: %d\n", v, segTree[v].suma);
    segTree[v].suma = val;
    v >>= 1;
    
    while(v) {
        //printf("v: %d, segTree[v].suma: %d\n", v, segTree[v].suma);
        segTree[v] = composeNodes(segTree[2*v], segTree[2*v + 1]);
        v >>= 1;
    }
}

long long sumOnRagne(int l, int r, int v) {
    if(segTree[v].left >= l && segTree[v].right <= r) return segTree[v].suma;
    if(segTree[v].left > r || segTree[v].right < l) return 0;
    return sumOnRagne(l, r, 2*v) + sumOnRagne(l, r, 2*v + 1);
}

int main() {
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> val[i];
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
	        addValue(in[v], val);
	    } else {
	        int v; cin >> v;
	        cout << sumOnRagne(in[v], out[v], 1) << "\n";
	    }
	}
	
}
