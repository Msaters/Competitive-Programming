#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long tab[107];

long long countValue(ll k, int n) {
    ll sum = k;
    for(int i = 0; i < n-1; i++) {
        sum += min(tab[i+1] - tab[i], k);
    }
    return sum;
}

long long bspowyniku(ll left, ll right, ll h, int n) {
    while(left < right) {
        ll mid = (left + right)/2;
        if(countValue(mid, n) >= h) {
            right = mid;
        } else {
            left = mid+1;
        }
    }
    
    return left;
}

int main() {
	int t; cin >> t;
	while(t) {
	    long long n, h; cin >> n >> h;
	    for(int i = 0; i < n; i++) {
	        cin >> tab[i];
	    }
	    
	    cout << bspowyniku(0, h, h, n) << endl;
	    t--;
	}

}