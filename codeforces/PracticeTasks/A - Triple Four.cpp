#include <iostream>
using namespace std;
int Arr[109];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> Arr[i];
    }
    
    bool was = false;
    for(int i = 0; i < n - 2; i++) {
        if(Arr[i] == Arr[i+1] && Arr[i+1] == Arr[i+2]) {
            was = true;
        }
    }
    if(was) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}