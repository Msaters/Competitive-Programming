#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int res = 0 - (n - 1);
        while(n--) {
            int a; cin >> a; res += a;
        }
        cout << res << endl;
    }

    return 0;
}