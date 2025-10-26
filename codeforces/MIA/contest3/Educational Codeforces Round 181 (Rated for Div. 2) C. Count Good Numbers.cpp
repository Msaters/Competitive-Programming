#include <bits/stdc++.h>
using namespace std;
 
 
long long good_remainders[210];
 
long long howManyGoodRemainders(long long r) {
    //cout << r << " " << r/210 * good_remainders[209] << " " << good_remainders[r%210] << endl;
    return r/210 * good_remainders[209] + good_remainders[r%210];  
}
 
int main() {
	for(long long i = 1; i < 210; i++) {
	    long long isGoodremainder = (long long) i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0;
	    good_remainders[i] = good_remainders[i-1] + isGoodremainder;
	}
	
	int t; cin >> t;
	while(t--) {
	    long long a, b; cin >> a >> b;
	    //cout << howManyGoodRemainders(b) << " " << howManyGoodRemainders(a) << endl;
	     cout << howManyGoodRemainders(b) - howManyGoodRemainders(a - 1) << endl;
	}
}