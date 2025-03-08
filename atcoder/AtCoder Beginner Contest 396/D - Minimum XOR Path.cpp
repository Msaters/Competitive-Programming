#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> G[11];
bool V[11];
long long res = 4611686018427387904;
long long n;

void dfs(long long v, long long akt) {
    V[v] = true;
    //cout << v << " akt: " << akt << endl;
    if(v == n) {
        res = min(res, akt);
    } else {
        for(pair<long long, long long> W : G[v]) {
            if(!V[W.first]) {
                dfs(W.first, akt ^ W.second);
            }
        } 
    }
    V[v] = false;
}

int main() {
    long long m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        long long a, b, w ; cin >> a >> b >> w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    dfs(1, 0);
    
    cout << res << endl;
    return 0;
}