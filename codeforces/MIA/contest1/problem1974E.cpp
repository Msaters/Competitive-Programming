#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 7;
const long long INF = 1e17 + 7;
long long dp[N];
 
int main() {
    for(int i = 1; i < N; i++) dp[i] = INF;
	int t; cin >> t;
	while(t) {
	    int m; long long x; int sumOfH = 0;
	    cin >> m >> x;
	    for(int i = 0; i < m; i++) {
	        long long c, h; cin >> c >> h;
	        long long money = x * (i);
	        for(int j = sumOfH; j >= 0; j--) {
	            if(dp[j] != INF) {
	                if(dp[j] + c <= money) {
	                    dp[j + h] = min(dp[j + h], dp[j] + c);
	                }
	            }
	        }
	        
	        sumOfH += h;
	    }
	    
	    int maxi = 0;
	    for(int i = 0; i <= sumOfH; i++) {
	        if(dp[i] != INF) maxi = i;
	    }
	    for(int i = 1; i <= sumOfH; i++) dp[i] = INF;
	    
	    cout << maxi << endl;
	    t--;
	}
 
}