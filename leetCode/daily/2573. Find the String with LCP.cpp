int n;
const int N = 1e3 + 7;
int R[N];
char RC[N];
vector<pair<int, int>> notEquals;

class Solution {

    int find(int a) {
        if(R[a] == a) return a;
        return R[a] = find(R[a]);
    }

    void unionS(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        R[rb] = ra;
    }

    bool validate(vector<vector<int>>& lcp) {
        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n-i) return false;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(lcp[i][j] > min(n-i, n-j)) return false;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(lcp[i][j] != lcp[j][i]) return false;
            }
        }

        return true;
    }

    void fillWord(int i, int j, int k) {
        int l = 0;
        for(l = 0; l < k; l++) {
            unionS(i+l, j+l);
        }

        if(l+i < n && l+j < n) {
            notEquals.push_back({l+i, l+j});
        }
    }

    bool fillMatrix(vector<vector<int>>& lcp) {
        for(int j = n-1; j >= 0; j--) {
            for(int i = 0; i <= j; i++) {
                fillWord(i, j, lcp[i][j]);
            }
        }

        for (auto notEq : notEquals) {
            auto [i, j] = notEq;
            if(find(i) == find(j)) return false;
        }

        return true;
    }

    string buildWord() {
        char start = 'a';
        for(int i = 0; i < n; i++) {
            if(RC[find(i)] == ' ') {
                if(start > 'z') return "";
                RC[find(i)] = start;
                start++;
            }
        }

        string res = "";
        for(int i = 0; i < n; i++) {
            res = res + RC[find(i)];
        }
        return res;
    }

public:


    string findTheString(vector<vector<int>>& lcp) {
        n = lcp.size();
        if(!validate(lcp)) return "";
        cout << "dupa\n";
        notEquals.clear();
        for(int i = 0; i < n; i++) {
            R[i] = i;
            RC[i] = ' ';
        }

        if(!fillMatrix(lcp)) return "";
        return buildWord();
    }
};