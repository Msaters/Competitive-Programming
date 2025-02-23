
//solved

#include <bits/stdc++.h>
using namespace std;
const int N = 3*1e6 + 9;
int PigC[N];
int PigeonsP[N];
int countN = 0;

int main() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        PigC[i] = 1;
        PigeonsP[i] = i;
    }
    
    for(int i = 0; i < q; i++) {
        int a; cin >> a;
        if(a == 1) {
            int p, h; cin >> p >> h;
            p--; h--;
            if(PigC[PigeonsP[p]] == 2) {
                countN--;
            }
            if(PigC[h] == 1) {
                countN++;
            }
            
            PigC[PigeonsP[p]]--;
            PigeonsP[p] = h;
            PigC[h]++;
        } else {
            /*cout << "printing \n";
            for(int i = 0; i < n; i++) {
                cout << i << " " << PigC[i] << "\n";
            }
            cout << "count: \n";*/
            cout << countN << endl;
        }
    }
   return 0;
}