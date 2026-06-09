#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int NimNum[N];

int mex(vector<int>& mexV, int k) {
    vector<bool> Values(k, false);
    for(int val : mexV) Values[val] = true;
    for(int i = 0; i < k; i++) if(!Values[i]) return i;
}

int main() {
    for(int i = 1; i < N; i++) {
        vector<int> mexV;
        for(int j = 1; j <= i; j++) {
            mexV.push_back(NimNum[max(0, j - 2)] ^ NimNum[min(i, i - j - 1)]);
        }
        NimNum[i] = mex(mexV, i+1);
    }
    
    int t; cin >> t;
    while(t) {
        int a; cin >> a;
        if(NimNum[a]) cout << "first";
        else cout << "second";
        cout << endl;
        t--;
    }

}
