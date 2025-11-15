#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 7; 
int arr[N];

bool canMakeItGcd(int n, int k, int g) {
    for(int i = 0; i < n; i++) {
        if(arr[i]%g != 0 && arr[i] < 4*g + arr[i]%g) {
            k--;
            if(k < 0) return false;
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    while(t) {
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
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