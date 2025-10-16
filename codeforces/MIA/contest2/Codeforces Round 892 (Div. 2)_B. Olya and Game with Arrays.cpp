#include <bits/stdc++.h>
using namespace std;


long long Arr[50009];
int main() {
	long long t; cin >> t;
	for(long long i = 0; i < t; i++){
	    long long n; cin>>n;
	    long long minF = 1e9 + 7; long long minS = 1e9 + 7; long long suma = 0;
	    for(long long j = 0; j < n; j++) { 
	        long long m; cin >> m;
	        for(long long k = 0; k < m; k++) {
    	        long long a; cin >> a;
    	        Arr[k] = a;
	        }
	        sort(Arr, Arr + m);
	        minF = min(minF, Arr[0]);
	        minS = min(minS, Arr[1]);
	        suma += Arr[1];
	    }
	    
	    cout << suma - minS + minF << endl;
	}
    return 0;
}