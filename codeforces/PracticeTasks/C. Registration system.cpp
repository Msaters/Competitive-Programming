#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> umap;

int main() {
    int n; cin >> n;
    while(n--) {
        string a; cin >> a; int hashedValue = umap[a];
        if(hashedValue == 0) {
            cout << "OK";
        } else {
            cout << a + to_string(hashedValue);
        }
        umap[a]++;
        cout << endl;
    }

    return 0;
}

// solved