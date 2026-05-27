#include <bits/stdc++.h>
using namespace std;

const int max_val = 1e6 + 7;
const int max_n = 5e5 + 7;

unsigned long long hashPrefix1[max_n];
unsigned long long hashPrefix2[max_n];
unsigned long long val_map[max_val];

int main() {
 
    int n, q; cin >> n >> q;
    
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < max_val; i++) {
        val_map[i] = rng();
    }
    
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        hashPrefix1[i] = hashPrefix1[i-1] ^ val_map[a];
    }
    
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        hashPrefix2[i] = hashPrefix2[i-1] ^ val_map[a];
    }
    
    for(int i = 0; i < q; i++) {
        int l, r, l2, r2; 
        cin >> l >> r >> l2 >> r2;
        
        if (r - l != r2 - l2) {
            cout << "NIE\n";
            continue;
        }
        
        unsigned long long hashA = hashPrefix1[r] ^ hashPrefix1[l-1];
        unsigned long long hashB = hashPrefix2[r2] ^ hashPrefix2[l2-1];
        
        if (hashA == hashB) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
    
    return 0;
}