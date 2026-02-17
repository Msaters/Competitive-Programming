#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	int t; cin >> t;
	while(t) {
	    int n; cin >> n;
	    set<int, greater<int>> numbers;
	    
	    for(int i = 0; i < n; i++) {
	        int a; cin >> a;
	        if(a%2 == 0)
	            numbers.insert(a);
	    }
	    
	    int moves = 0;
	    while(!numbers.empty()) {
	        int newNum = (*numbers.begin())/2;
	        numbers.erase(numbers.begin());
	        moves++;
	        if(newNum%2 == 0) numbers.insert(newNum);
	    }
	    
	    cout << moves << endl;
	    t--;
	}
 
}