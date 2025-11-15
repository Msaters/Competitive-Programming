#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N = 1e5+7;
int pref[N];
int arr[N];

int findMax(int l, int r, int t) {
    int start = l;
    while(l < r) {
        int mid = (l+r+1)/2;
        ll sum = pref[mid] - pref[start-1];
        if(sum > t) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    if(arr[r] > t) return 0;
    return r - start + 1;
}

int main() {
	int n, t; cin >> n >> t;
	for(int i = 1; i <= n; i++) {
	    cin >> arr[i];
	    pref[i] = pref[i-1] + arr[i];
	}
	
	int maxi = 0;
	for(int i = 1; i <= n; i++) {
	    maxi = max(maxi, findMax(i, n, t));
	}
	cout << maxi;

}
