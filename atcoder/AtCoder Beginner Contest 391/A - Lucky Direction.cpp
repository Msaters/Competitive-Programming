
//solved

#include <bits/stdc++.h>
using namespace std;


int main() {
    string d; cin >> d;
    string output = "";
    if(d == "N") {
        output = "S";
    }
    
    if(d == "S") {
        output = "N";
    }
    
    if(d == "E") {
        output = "W";
    }
    
    if(d == "W") {
        output = "E";
    }
    
    if(d == "NE") {
        output = "SW";
    }
    
    if(d == "SW") {
        output = "NE";
    }
    
    if(d == "NW") {
        output = "SE";
    }
    
    if(d == "SE") {
        output = "NW";
    }

    cout << output;

    return 0;
}