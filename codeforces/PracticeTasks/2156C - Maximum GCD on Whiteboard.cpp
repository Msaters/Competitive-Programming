#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 7; 
int arr[N];
int prefArr[N];

bool canMakeItGcd(int n, int k, int g) {
    int withGcd = prefArr[g] - prefArr[g-1];
    
    if(n >= g*2) withGcd += prefArr[g*2] - prefArr[g*2-1];
    if(n >= g*3) withGcd += prefArr[3*g] - prefArr[3*g - 1];
    if(n >= g*4) withGcd += prefArr[n] - prefArr[4*g-1];
    return withGcd >= n - k;
}

int main() {
    int t; cin >> t;
    while(t) {
        int n, k; cin >> n >> k;
        for(int i = 0; i <= n; i++) prefArr[i] = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            prefArr[arr[i]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            prefArr[i] += prefArr[i-1];
        }
        
        for(int i = n; i >= 1; i--) {
            if(canMakeItGcd(n, k, i)) {
                cout << i << endl;
                break;
            }
        }
        t--;
    }
}