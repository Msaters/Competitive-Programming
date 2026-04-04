#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    vector<int> arr;
	    for(int i = 0; i < n; i++) {
	        int a; cin >> a;
	        arr.push_back(a);
	    }
	    
	    int res = 0;
	    for(int i = 1; i < n - 1; i++) {
	        if(arr[i] == -1) arr[i] = 0;
	    }
	    
	    if(arr[0] == arr[n-1] && arr[0] == -1) {
	        arr[0] = 0;
	        arr[n-1] = 0;
	    } else {
	        if(arr[0] == -1) {
	            arr[0] = arr[n-1];
	        }
	        
	        if(arr[n-1] == -1) {
	            arr[n-1] = arr[0];
	        }
	    }
	    
	    if(arr[0] != -1 && arr[n-1] != -1) {
	        res = abs(arr[0] - arr[n-1]);
	    }
	    
	    cout << res << endl;
	    for(int i = 0; i < n; i++) {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    t--;
	}

}