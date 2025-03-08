#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int B[N];
int W[N];
long long maxSum = 0;

int main() {
   int n, m; cin >> n >> m;
   for(int i = 0 ; i < n; i++) {
       cin >> B[i];
   }
   for(int j = 0; j < m; j++) {
       cin >> W[j];
   }
   sort(B, B+n, greater<int>());
   sort(W, W+m, greater<int>());
   int k = 0; int l = 0;
    while(B[k] > 0 && k < n) {
        maxSum += B[k];
        k++;
    }
    
    while(W[l] > 0 && l < k && l < m) {
        maxSum += W[l];
        l++;
    }
    
    if(k == l) {
        while(W[l] + B[l] > 0 && l < m && k < n) {
            maxSum += W[l] + B[l];
            l++; k++;
        }
    }
    
    cout << maxSum << endl;
    return 0;
}