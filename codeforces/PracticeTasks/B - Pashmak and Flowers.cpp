#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
 
int mini = 1e9+9;
int maks = 0;
map<int,int> M;
 
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        M[a]++;
        maks = max(a, maks);
        mini = min(mini, a);
    }
    long long res = (long long) M[mini] * M[maks];
    if(maks - mini == 0) res = ((long long) M[mini] * (M[mini] - 1))/2;
    cout << maks - mini << " " << res;
}