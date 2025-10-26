#include <bits/stdc++.h>
using namespace std;

const int N = 5007;
bool isPalindrom[N][N];
long long dp[N][N];

int main() {
    ios::sync_with_stdio(0);
	string s; cin >> s;
	int n = s.length();
	int q; cin >> q;
	
	for(int i = 0; i < n; i++) {
	    for(int start = 0; start < n-i; start++) {
	        int end = start + i;
	        if(i == 0) {
	            isPalindrom[start][start] = 1;
	        } else {
	            if(i == 1) {
	                isPalindrom[start][end] = s[start] == s[end];
	            } else {
	                isPalindrom[start][end] = s[start] == s[end] && isPalindrom[start+1][end-1];
	            }
	        }
	    }
	}
	
	
	
	for(int step = 0; step < n; step++) {
	    for(int start = 0; start < n-step; start++) {
	        int end = start + step;
	        switch(step) {
	            case 0:
	                dp[start][end] = 1;
	                break;
	            case 1:
	                dp[start][end] = 2 + isPalindrom[start][end];
	                break;
	            default:
	                dp[start][end] = dp[start][end-1] + dp[start+1][end] - dp[start+1][end-1] + isPalindrom[start][end];
	        }
	    }
	}
	
	while(q--) {
	    int l, r; cin >> l >> r;
	    cout << dp[l-1][r-1] << endl;
	}
	

}