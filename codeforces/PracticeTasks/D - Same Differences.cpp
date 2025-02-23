#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
 
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;  
        map<int, int> m;
        long long res = 0;
        for(int i = 0; i < n; i++) 
        {
            int a; cin >> a;
            a -= i + 1;
            res += m[a];
            m[a]++;
        }
 
        cout << res << endl;
        
    }
 
    return 0;
}

// solved with big help of editorial