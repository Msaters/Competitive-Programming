#include <bits/stdc++.h>

using namespace std;

set < int > firstSet;

int findFirstDivisor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

void getPrimesSet(set < int > & S, int n) {
    while (n != 1) {
        int divisor = findFirstDivisor(n);
        S.insert(divisor);
        n /= divisor;
    }
}


pair < int, int > maxElem;
int main() {

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    getPrimesSet(firstSet, a);
    getPrimesSet(firstSet, b);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (auto it = firstSet.begin(); it != firstSet.end();) {
            int elem = *it;
            if(a%elem != 0 && b%elem != 0) {
                it = firstSet.erase(it);
            } else {
                it++;
            }
        }
    }
    
    if (firstSet.empty()) {
       cout << "-1" << endl; 
    } else {
        cout << *firstSet.begin() << endl;
    }

}