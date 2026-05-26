#include <bits/stdc++.h>
#define ll long long
using namespace std;


const ll m = 1e9 + 7;
const ll mod2 = 1e9 + 9;

ll hashV(string& x, int i, int j, ll m) {
    ll hashVal = 0;
    ll factor = 1;
    for(i; i < j; i++) {
        hashVal = (hashVal + factor * x[i]) % m;
        factor =  (factor * 26) % m;
    }
    return hashVal;
}

ll getRightFactor(int n, ll m) {
    ll factor = 1;
    while(n) {
        factor = (factor * 26) % m;
        n--;
    }
    return factor;
}


tuple<ll, ll, ll, ll> next(ll wzorzecHash, ll tekstHash, ll leftFactor, ll rightFactor, ll m, char leftChar, char rightChar) {
    // wzorzecHash, tekstHash, leftFactor, rightFactor
    wzorzecHash = (wzorzecHash * 26) % m;
    ll sub = (leftChar * leftFactor) % m;
    tekstHash = (tekstHash - sub) < 0 ? tekstHash - sub + m : tekstHash - sub;
    tekstHash = (tekstHash + rightChar * rightFactor) % m;
    leftFactor = (leftFactor * 26) % m;
    rightFactor = (rightFactor * 26) % m;
    return {wzorzecHash, tekstHash, leftFactor, rightFactor};
}


int main() {
	string a, b; cin >> a >> b;
	if(b.length() > a.length()) {
	    cout << 0;
	    return 0;
	}
	
    ll wzorzecHash = hashV(b, 0, b.length(), m);
    ll tekstHash = hashV(a, 0, b.length(), m);
    
    ll wzorzecHash2 = hashV(b, 0, b.length(), mod2);
    ll tekstHash2 = hashV(a, 0, b.length(), mod2);
    
    int counter = 0; 
    ll leftFactor2 = 1, leftFactor = 1;
    ll rightFactor = getRightFactor(b.length(), m), rightFactor2 = getRightFactor(b.length(), mod2);
    
    for(int i = b.length(); i < a.length(); i++) {
        if(tekstHash == wzorzecHash && tekstHash2 == wzorzecHash2) counter++;
        tie(wzorzecHash, tekstHash, leftFactor, rightFactor) = next(wzorzecHash, tekstHash, leftFactor, rightFactor, m, a[i - b.length()], a[i]);
        tie(wzorzecHash2, tekstHash2, leftFactor2, rightFactor2) = next(wzorzecHash2, tekstHash2, leftFactor2, rightFactor2, mod2, a[i - b.length()], a[i]);
    }
    if(tekstHash == wzorzecHash && tekstHash2 == wzorzecHash2) counter++;
    
    cout << counter;
}
