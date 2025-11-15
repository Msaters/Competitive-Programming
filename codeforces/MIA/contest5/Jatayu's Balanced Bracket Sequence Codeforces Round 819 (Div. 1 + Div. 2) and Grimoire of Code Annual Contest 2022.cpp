#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 7;
int depths[N];
 
int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    int comps = 0; 
	    for(int i = 1; i <= n; i++) depths[i] = -1;
	    int depth = 0;
	    for(int i = 0; i < 2*n; i++) {
	        char a; cin >> a;
	        if(a == '(') {
	            depth++;
	        } else {
	            if(depths[depth] == -1) {
	                comps++;
	            } else {
	                if(depths[depth] < depths[depth-1] & depth != 1) {
	                    comps++;
	                }
	            }
	            depths[depth] = i;
	            depth--;
	        }
	    }
	    
	    cout << comps << endl;
	    t--;
	}
 
}