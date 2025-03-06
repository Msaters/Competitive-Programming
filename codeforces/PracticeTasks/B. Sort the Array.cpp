#include <iostream>
using namespace std;
const int N = 1e5 + 9;
int start = -1, finish;
int arr[N];

int main() {
    bool unable = false;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++) {
        if(arr[i-1] > arr[i] + 1) unable = true;
        if(arr[i-1] == arr[i] - 1) {
            cout << "replace " << arr[i-1] << " " << arr[i] << endl;
            if(finish != 0 && finish != i - 1) unable = true;
            if(start == -1) start = i-1;
            finish = i;
        } 
    }
    
    if(unable) {
        cout << "No";
    } else {
        cout << "yes" << endl << start + 1 << " " << finish + 1;
    }
    return 0;
}

// not finished