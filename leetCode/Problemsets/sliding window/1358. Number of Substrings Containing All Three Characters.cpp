const int max_n = 5 * 1e4 + 7;
int prefix[max_n][4];

class Solution {
private:
    bool check(int l, int r) {
        for(int k = 0; k < 3; k++) {
            if(prefix[r][k] - prefix[l - 1][k] == 0) return false;
        }
        return true;
    }

    int binary_search(int l, int r) {
        int left = l;
        while(l < r) {
            int mid = (l + r) / 2;
            if(check(left, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        for(int i = 1; i <= n; i++) {
            for(int k = 0; k < 3; k++) {
                prefix[i][k] = prefix[i - 1][k];
            }
            prefix[i][s[i - 1] - 'a'] = prefix[i - 1][s[i - 1] - 'a'] + 1;
        }

        int numSubs = 0;
        for(int i = 1; i <= n; i++) {
            int r = binary_search(i, n);
            if(!check(i, r)) continue;
            numSubs += n - r + 1;
           // printf("i: %d, r: %d, numSubs: %d, n - r + 1: %d\n", i, r, numSubs, n - r + 1);
        }
        return numSubs;
    }
};