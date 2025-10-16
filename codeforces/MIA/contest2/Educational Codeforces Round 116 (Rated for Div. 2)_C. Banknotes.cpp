#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

string reverselong(long long i) {
    string stringToAdd = to_string(i);
    reverse(all(stringToAdd));
    return stringToAdd;
}

long long Arr[50009];
int main() {
	long long t; cin >> t;
	for(long long i = 0; i < t; i++){
	   vector<long long> v;
	   long long n, k; cin >> n >> k;
	   for(long long i = 0; i < n; i++) {
	       long long a; cin >>a;
	       v.push_back(a);
	   }
	   v.push_back(100);
	   sort(all(v)); 
	   string number = "";
	   long long space = 1; long long ind = 0;
	   k++;
	   while(k != 0) {
	       if(k < pow(10, space) - 1) {
	           number += reverselong(k);
	           k = 0;
	       } else {
	           space++;
	           if(space > v[ind+1] - v[ind]) {
	               space--;
	               //cout << space << " " << v[ind+1] - v[ind] << " " << to_string((long long) pow(10, space) - 1) << endl;
	               number += reverselong((long long) pow(10, space) - 1);
	               k -= pow(10, space) - 1;
	               space = 1; ind++;
	           }
	       }
	   }
	   reverse(all(number));
	   cout << number << endl;
	}
    return 0;
}