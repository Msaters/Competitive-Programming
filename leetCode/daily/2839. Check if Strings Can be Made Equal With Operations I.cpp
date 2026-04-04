static const int N = 256;
int Evens[N];
int Odds[N];

int Evens2[N];
int Odds2[N];

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.length();
        for(int i = 0; i < N; i++) {
            Evens[i] = 0;
            Odds[i] = 0;
            Evens2[i] = 0;
            Odds2[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            if(i%2==0) {
                Evens[s1[i]]++ ;
            } else {
                Odds[s1[i]]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i%2==0) {
                Evens2[s2[i]]++ ;
            } else {
                Odds2[s2[i]]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                if(Evens[s2[i]] != Evens2[s2[i]]) return false;
            } else {
                if(Odds[s2[i]] != Odds2[s2[i]]) return false;
            }
        }

        return true;
    }
};