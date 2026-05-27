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

long long hashSuifx1[max_n];
long long hashSuifx2[max_n];
ll P1_S[max_n];
ll P2_S[max_n];

bool isPalindrome(int L, int R) {
    if (L >= R) return true;

    ll h1_norm = (hashPrefix1[R + 1] - hashPrefix1[L]) % m;
    if (h1_norm < 0) h1_norm += m;
    
    ll h1_rev = (hashSuifx1[L] - hashSuifx1[R + 1]) % m;
    if (h1_rev < 0) h1_rev += m;
    
    if ((h1_norm * P1_S[R + 1]) % m != (h1_rev * P1[L]) % m) return false;

    ll h2_norm = (hashPrefix2[R + 1] - hashPrefix2[L]) % mod2;
    if (h2_norm < 0) h2_norm += mod2;
    
    ll h2_rev = (hashSuifx2[L] - hashSuifx2[R + 1]) % mod2;
    if (h2_rev < 0) h2_rev += mod2;
    
    if ((h2_norm * P2_S[R + 1]) % mod2 != (h2_rev * P2[L]) % mod2) return false;

    return true;
}

int main() {
    
    string a; cin >> a;
    int n = a.length();
    
    P1[0] = 1; P2[0] = 1;
    for(int i = 1; i <= n; i++) {
        hashPrefix1[i] = (hashPrefix1[i-1] + a[i-1] * P1[i-1]) % m;
        P1[i] = (P1[i-1] * 26) % m;
        
        hashPrefix2[i] = (hashPrefix2[i-1] + a[i-1] * P2[i-1]) % mod2;
        P2[i] = (P2[i-1] * 26) % mod2;
    }
    
    P1_S[n] = 1; P2_S[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        hashSuifx1[i] = (hashSuifx1[i+1] + a[i] * P1_S[i+1]) % m;
        P1_S[i] = (P1_S[i+1] * 26) % m;
        
        hashSuifx2[i] = (hashSuifx2[i+1] + a[i] * P2_S[i+1]) % mod2;
        P2_S[i] = (P2_S[i+1] * 26) % mod2;
    }
    
    int biggestLength = 0;
    int bestStart = 0;
    
    for(int i = 0; i < n; i++) {
        int l = 0, r = min(i, n - 1 - i);
        // niepatrzyste
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(!isPalindrome(i - mid, i + mid)) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if(2 * l + 1 > biggestLength) {
            biggestLength = 2 * l + 1;
            bestStart = i - l;
        }
        
        // parzyste
        if (i + 1 < n && a[i] == a[i+1]) {
            int l2 = 1, r2 = min(i + 1, n - 1 - i);
            while(l2 < r2) {
                int mid = (l2 + r2 + 1) / 2;
                if(!isPalindrome(i - mid + 1, i + mid)) {
                    r2 = mid - 1;
                } else {
                    l2 = mid;
                }
            }
            if(2 * l2 > biggestLength) {
                biggestLength = 2 * l2;
                bestStart = i - l2 + 1;
            }
        }
    }
    
    cout << a.substr(bestStart, biggestLength) << "\n";
    
    return 0;
}