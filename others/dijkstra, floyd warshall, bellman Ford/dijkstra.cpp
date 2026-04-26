#include <bits/stdc++.h>
using namespace std;

const int max_N = 1e5 + 7;
long long dist[max_N];
vector<pair<long long, int>> G[max_N];
long long INF = 1e18;

void dikstra(int v) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[v] = 0;
    pq.push({0, v});
    
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d == dist[u]) {
            for(auto pa : G[u]) {
                auto [e, w] = pa;
                if(d + e < dist[w]) {
                    dist[w] = d + e;
                    pq.push({dist[w], w});
                }
            }
        }
    }
}

int main() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
	    int a, b, d;
	    cin >> a >> b >> d;
	    G[a].push_back({d, b});
	}
	
	for(int i = 0; i <= n; i++) {
	    dist[i] = INF;
	}
	
	dikstra(1);
	
	for(int i = 1; i <= n; i++) {
	    cout << dist[i] << " ";
	}

}
