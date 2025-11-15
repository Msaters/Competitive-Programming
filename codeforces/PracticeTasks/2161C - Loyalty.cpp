#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 7;
int arr[N];

int main() {
    int t; cin >> t;
    while(t) {
        int n, X; cin >> n >> X;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        
        int l = 0; int r = n-1; ll sum = 0; int level = 0; ll result = 0;
        vector<int> resVec;
        while(l <= r) {
            //cout << "l: " << l <<" arr[l]: " << arr[l] << " r: " << r << " arr[r]: " << arr[r] << endl;
            //cout << "sum: " << sum << " lrvrl: " << level << " " << result << " " <<  sum+arr[r] << " " << (sum+arr[r])/X << endl; 
            if((sum+arr[r])/X > level) {
                sum += arr[r];
                level = sum/X;
                result += arr[r];
                resVec.push_back(arr[r]);
                r--;
            } else {
                sum += arr[l];
                resVec.push_back(arr[l]);
                l++;
            }
        }
        
        cout << result << endl;
        for(auto elem : resVec) {
            cout << elem << " ";
        }
        cout << endl;
        t--;
    }
}