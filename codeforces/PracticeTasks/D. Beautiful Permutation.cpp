#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll query(int type, int l, int r){
    ll x;
    cout << type << ' ' << l << ' ' << r << flush << endl;
    cin >> x;
    return x;
}

bool isContam(int l, int r) {
    return query(1, l, r) != query(2, l, r);
}

int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    int l = 1, r = n;
	    while(l < r) {
    	    int mid = (l+r)/2;
    	    if(isContam(l, mid)) {
    	        r = mid;
    	    } else {
    	        l = mid + 1;
    	    }
	    }
	    
	    ll right = query(2, 1, n) - query(1, 1, n) + l - 1;
	    cout << "! " << l << " " << right << endl;
	    t--;
	}

}
