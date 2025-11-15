#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t) {
	    int n, k; cin >> n >> k;
	    if((n - (k-1))%2 == 1 && (n - (k-1)) > 0) {
	        cout << "YES" << endl;
	        for(int i = 0; i < k - 1; i++) {
	            cout << "1 ";
	        }
	        cout << (n - (k-1));
	    } else {
	        int minus = (k-1)*2;
	        if((n - minus)%2 == 0 && (n - minus) > 0) {
	            cout << "YES" << endl;
	            for(int i = 0; i < k - 1; i++) {
	                cout << "2 ";
	            }
	        cout << (n - minus);
	        } else {
	            cout << "NO";
	        }
	    }
	    cout << endl;
	    t--;
	}

}
