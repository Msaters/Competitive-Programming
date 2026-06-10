#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    bool wasOdd = false;
	    while(n) {
	        int a; cin >> a;
	        wasOdd |= a%2;
	        n--;
	    }
	    
	    if(wasOdd) cout << "first";
	    else cout << "second";
	    cout << endl;
	    t--;
	}

}
