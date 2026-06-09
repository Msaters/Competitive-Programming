#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+7;
int NimNum[N][N];

int mex(vector<int>& mexV, int k) {
    vector<bool> Values(k, false);
    for(int val : mexV) Values[val] = true;
    for(int i = 0; i < k; i++) if(!Values[i]) return i;
}

int main() {
    for(int i = 1; i < N; i++) {
        int y = i, x = 0;
        while(y >= 0 && x < N) {
            vector<int> mexV;
            if(y - 2 >= 0 && x - 1 >= 0) mexV.push_back(NimNum[y-2][x-1]);
            if(y - 2 >= 0 && x + 1 < N) mexV.push_back(NimNum[y-2][x+1]);
            if(x - 2 >= 0 && y - 1 >= 0) mexV.push_back(NimNum[y-1][x-2]);
            if(x - 2 >= 0 && y + 1 < N) mexV.push_back(NimNum[y+1][x-2]);
            NimNum[y][x] = mex(mexV, 10);
            y--; x++;
        }
    }
    
    int t; cin >> t;
    while(t) {
        int n; cin >> n;
        int S = 0;
        while(n) {
            int x, y; cin >> x >> y;
            S ^= NimNum[y-1][x-1];
            n--;
        }
        
        if(S) cout << "first";
        else cout << "second";
        cout << endl;
        t--;
    }

}
