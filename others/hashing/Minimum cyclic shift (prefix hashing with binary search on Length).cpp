#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll m = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const int max_n = 2 * 1e6 + 7;

long long hashPrefix1[max_n];
long long hashPrefix2[max_n];
ll P1[max_n];
ll P2[max_n];

bool isEqual(int idx1, int idx2, int len) {
    if (len == 0) return true;

    ll h1_1 = (hashPrefix1[idx1 + len] - hashPrefix1[idx1]) % m;
    if (h1_1 < 0) h1_1 += m;
    ll h1_2 = (hashPrefix1[idx2 + len] - hashPrefix1[idx2]) % m;
    if (h1_2 < 0) h1_2 += m;
    
    if ((h1_1 * P1[idx2]) % m != (h1_2 * P1[idx1]) % m) return false;

    ll h2_1 = (hashPrefix2[idx1 + len] - hashPrefix2[idx1]) % mod2;
    if (h2_1 < 0) h2_1 += mod2;
    ll h2_2 = (hashPrefix2[idx2 + len] - hashPrefix2[idx2]) % mod2;
    if (h2_2 < 0) h2_2 += mod2;
    
    if ((h2_1 * P2[idx2]) % mod2 != (h2_2 * P2[idx1]) % mod2) return false;

    return true;
}

int getBestIndex(int currBestIndex, int currIndex, int n, string& a) {
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(!isEqual(currBestIndex, currIndex, mid)) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    
    if(l == n) return currBestIndex;
    if(a[currBestIndex + l] > a[currIndex + l]) return currIndex;
    return currBestIndex;
}

int main() {
    
    string a; cin >> a;
    int n = a.length();
    a += a;
    
    P1[0] = 1; P2[0] = 1;
    for(int i = 1; i <= 2*n; i++) {
        hashPrefix1[i] = (hashPrefix1[i-1] + a[i-1] * P1[i-1]) % m;
        P1[i] = (P1[i-1] * 26) % m;
        
        hashPrefix2[i] = (hashPrefix2[i-1] + a[i-1] * P2[i-1]) % mod2;
        P2[i] = (P2[i-1] * 26) % mod2;
    }
    
    int bestIndex = 0;
    for(int i = 1; i < n; i++) {
        bestIndex = getBestIndex(bestIndex, i, n, a);
    }
    
    cout << a.substr(bestIndex, n) << "\n";
    return 0;
}