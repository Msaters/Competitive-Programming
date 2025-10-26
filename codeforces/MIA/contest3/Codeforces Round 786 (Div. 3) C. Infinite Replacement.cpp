#include <iostream>
using namespace std;
 
int main() {
    int t; cin>>t;
    
    for(int i = 0; i < t; i++)
    {
        string a,b;
        cin>>a>>b;
        
        bool wasThere = false;
        for(int j = 0; j < b.length(); j++)
        {
            if(b[j] == 'a') wasThere = true;
        }
        
        if(wasThere && b.length() > 1)
        {
            cout << -1 << "\n";
            continue;
        }
        
        long long wyn = 1;
        if(wasThere && b.length() == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        
        for(int j = 0; j < a.length(); j++)
        {
            wyn*=2;
        }
        cout << wyn << "\n";
    }
    return 0;
}