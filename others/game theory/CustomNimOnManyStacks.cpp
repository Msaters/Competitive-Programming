#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int NimNum[N];

int mex(vector<int>& mexV) {
    vector<bool> Values(5, false); // maxymalna wartosc to 3
    for(int val : mexV) Values[val] = true;
    for(int i = 0; i < 5; i++) if(!Values[i]) return i;
}

int main() {
    NimNum[1] = 1;
    NimNum[3] = 1;
    for(int i = 4; i < N; i++) {
        vector<int> mexV = {NimNum[i - 1], NimNum[i-3], NimNum[i-4]};
        NimNum[i] = mex(mexV);        
    }
    
    
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    int S = 0;
	    while(n) {
	        int a; cin >> a;
	        S ^= NimNum[a];
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
