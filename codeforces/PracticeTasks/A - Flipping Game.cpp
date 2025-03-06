#include <iostream>
#include <cmath>
using namespace std;
const int N = 109;
int Ones[N];
int Zeroes[N];
 
int numberOfOnes(int i, int j, int n) {
    int res = 0;
    if(i != 0) res += Ones[i-1];
    res += Ones[n] - Ones[j];
    res += (Zeroes[j] - Zeroes[i-1]);
    
    //cout << endl << Ones[i-1] << " " << Ones[n] - Ones[j] << " " << (Zeroes[j] - Zeroes[i-1]) << endl;
    return res;
}
 
int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(a == 1) {
            Ones[i]++;
        } else {
            Zeroes[i]++;
        }
        Ones[i] += Ones[i-1];
        Zeroes[i] += Zeroes[i-1];
    }
    
    int maks = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            //cout << i << " " << j << " " << numberOfOnes(i, j, n) << endl;
            maks = max(maks, numberOfOnes(i, j, n));
        }
    }
    
    cout << maks << endl;
    return 0;
}