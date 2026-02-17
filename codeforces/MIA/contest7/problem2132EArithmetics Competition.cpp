#include <bits/stdc++.h>
using namespace std;

const int N = 2*1e5 + 7;
long long prefA[N];
long long prefB[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a, b;
        
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            a.push_back(num);
        }
        
        for (int i = 0; i < m; i++) {
            int num; cin >> num;
            b.push_back(num);
        }
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
    
        for (int i = 1; i <= n; i++)
            prefA[i] = a[i-1] + prefA[i-1];
            
        for (int i = 1; i <= m; i++)
            prefB[i] = b[i-1] + prefB[i-1];
    
        vector<pair<int,int>> ans;
        ans.push_back({0, 0});
        int l = 0, r = 0;
        for (int i = 0; i < n+m; i++) {
            if (l < n && r < m) {
                if(a[l] < b[r])
                    r++;
                else
                    l++;
            }
            else if (l == n)
                r++;
            else if (r == m)
                l++;
            ans.push_back({l, r});
        }
    
        for (int i = 0; i < q; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            l = ans[z].first, r = ans[z].second;
            if (l > x)
                cout << prefA[x] + prefB[z - x] << '\n';
            else if (r > y)
                cout << prefA[z - y] + prefB[y] << '\n';
            else
                cout << prefA[l] + prefB[r] << '\n';
        }
    }
    
}