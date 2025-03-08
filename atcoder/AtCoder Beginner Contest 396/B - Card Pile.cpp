#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        if(q == 1) {
            int x; cin >> x;
            st.push(x);
        } else {
            if(!st.empty()) {
                cout << st.top();
                st.pop();
            } else {
                cout << 0;
            }
            cout << endl;
        }
    }
    
    

    return 0;
}