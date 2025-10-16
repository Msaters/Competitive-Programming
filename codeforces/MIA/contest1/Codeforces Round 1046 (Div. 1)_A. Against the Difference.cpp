#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 7;
int DP[N], a[N]; deque<int> Qs[N]; 
int main() {
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n; DP[0] = 0;
	    for(int i = 1; i <= n; i++) Qs[i].clear();
	    for(int i = 1; i <= n; i++) cin >> a[i];
	    for(int i = 1; i <= n; i++) {
            Qs[a[i]].push_back(i);
            DP[i] = DP[i - 1];
	        if(Qs[a[i]].size() > a[i]) Qs[a[i]].pop_front();
	        if(Qs[a[i]].size() == a[i]) {
	            //cout << "size: " << Qs[a[i]].size() << endl;
	            DP[i] = max(DP[Qs[a[i]].front() - 1] + a[i],  DP[i - 1]);
	        }
	        //cout << "i: " << i << " DP[i]: " << DP[i] << endl; 
	    }
	    
	    cout << DP[n] << endl;
	}

}
