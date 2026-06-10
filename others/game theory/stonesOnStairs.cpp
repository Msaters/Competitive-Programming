#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    int S = 0;
	    for(int i = 1; i <= n; i++) {
	        int a; cin >> a;
	        if(i%2 == 0) S ^= a;
	    }
	    
	    if(S) cout << "first";
	    else cout << "second";
	    cout << endl;
	    t--;
	}

}
