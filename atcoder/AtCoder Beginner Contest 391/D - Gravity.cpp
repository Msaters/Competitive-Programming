
//solved

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int N = 2*1e5 + 9;
const int INF = N*10;
vector<pair<int, int>> Colums[N];
int Order[N];
int Answear[N];
int n, w; 

int biggestInRow(int rowNumber) {
    int maks = 0;
    for(int i = 0; i < w; i++) {
        int size = Colums[i].size();
        if(size - 1 < rowNumber) return INF;
        maks = max(maks, Colums[i][rowNumber].f);
    }
    return maks;
}

int main() {
   cin >> n >> w;
   for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        Colums[x-1].push_back({y, i});
   }
   
   for(int i = 0; i < w; i++) {
       sort(Colums[i].begin(), Colums[i].end());
   }
   
   int maxSize = 0;
   for(int i = 0; i < w; i++) {
       int size = Colums[i].size();
       maxSize = max(maxSize, size);
       for(int j = 0; j < size; j++) {
           Order[Colums[i][j].s] = j;
       }
   }
   
   /*for(int i = 0; i < n; i++) {
       cout << i << " " << Order[i] << endl;
   }*/
   
   for(int i = 0; i < maxSize; i++) {
       Answear[i] = biggestInRow(i);
       //cout << "row: " << i << "  " << Answear[i] << "\n";
   }
   
    
   int q; cin >> q;
   for(int i = 0; i < q; i++) {
       int t, a; cin >> t >> a; 
       a--;
       //cout << t << " " << a << " " << Order[a] << " " << Answear[Order[a]]  << " " << endl;
       
       if(Answear[Order[a]] <= t && Answear[Order[a]] != INF) {
           cout << "No" << endl;
       } else {
           cout << "Yes" << endl;
       }
   }
   
   return 0;
}