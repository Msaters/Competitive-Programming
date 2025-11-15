#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 * 2 + 7;
int R[N];
int S[N];
int nextArr[N];

int find(int a) {
    if (a == R[a]) return a;
    return R[a] = find(R[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (S[a] < S[b]) {
        R[a] = b;
        S[b] += S[a];
    } else {
        R[b] = a;
        S[a] += S[b];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        R[i] = i;
        S[i] = 1;
        nextArr[i] = i+1;
    }

    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        //cout << type << " " << x << " " << y << endl;
        switch (type) {
            case 1:
                Union(x, y);
                break;
            case 2:
                int nextElem;
                for (int j = x; j <= y; j = nextElem) {
                    Union(x, j);
                    nextElem = nextArr[j];
                    nextArr[j] = nextArr[y];
                }
                break;
            case 3:
                if (find(x) == find(y)) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
                cout << endl;
        }
    }

}