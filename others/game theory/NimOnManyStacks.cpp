#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    int S = 0;
	    while(n) {
	        int a; cin >> a;
	        S ^= a;
	        n--;
	    }
	    
	    if(S > 0) {
	        cout << "first";
	    } else {
	        cout << "second";
	    }
	    cout << endl;
	    
	    t--;
	}

}
