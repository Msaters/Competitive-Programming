#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        unsigned x; cin >> x;
        int countOnes = __builtin_popcount(x);
        int countZeroes = __builtin_clz(x);
        if(countOnes == 1 || countOnes == 32 - countZeroes) {
            cout << -1;
        } else {
            bool wasZero = false; bool wasOne = false;
            int res = 0; int mult = 1;
            while(!wasZero || !wasOne) {
                if(x%2 == 0) {
                    if(!wasZero) {
                        wasZero = true;
                        res += mult;
                    }
                } else {
                    if(!wasOne) {
                        wasOne = true;
                        res += mult;
                    }
                }
                mult *= 2;
                x /= 2;
            }
            cout << res;
        }
        cout << endl;
    }

    return 0;
}