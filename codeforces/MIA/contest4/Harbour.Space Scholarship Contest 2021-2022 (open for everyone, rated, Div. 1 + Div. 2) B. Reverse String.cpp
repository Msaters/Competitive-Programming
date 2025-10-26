#include <bits/stdc++.h>
using namespace std;

bool was;

void goingLeft(int i, string& s, string& t, int akt);
void goingRight(int i, string& s, string& t, int akt) {
    if(i == s.length() || s[i] != t[akt] ) {
        return;
    }
    
    akt++;
    if(akt == t.length()) {
        //cout << t.length() << endl;
        //cout << "right, i: " << i << endl;
        was = true;
        return;
    }
    //cout << "right i: " << i << " akt: " << akt << " " << s << " " << t << endl;
    goingRight(i + 1, s, t, akt);
    goingLeft(i-1, s, t, akt);
    
}

void goingLeft(int i, string& s, string& t, int akt) {
    if(i == -1 || s[i] != t[akt]) { 
        //cout << "dying i: " << i << " akt: " << akt << " " << s << " " << t << endl;
        return;
    }
    if(akt + 1 == t.length()) {
        //cout << "left, i: " << i << endl;
        was = true;
        return;
    }
     //cout << "left i: " << i << " akt: " << akt << " " << s << " " << t << endl;
    goingLeft(i - 1, s, t, akt + 1);
}

int main() {
	int t; cin >> t;
	while(t--) {
	    string s, l; cin >> s >> l; was = false;
	    for(int i = 0; i < s.length(); i++) {
	        goingRight(i, s, l, 0);
	    }
	    
	    if(was) {
	        cout << "Yes" << endl;
	    } else {
	        cout << "No" << endl;
	    }
	    
	}

}