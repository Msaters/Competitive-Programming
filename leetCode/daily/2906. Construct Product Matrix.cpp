int m, n;
int mod = 12345;

static const int NM = 1e5 + 7;
int suffix[NM];

class Solution {
private:
public:

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        suffix[n*m] = 1;
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int currElement = grid[i][j] % mod;
                suffix[i*n + j] = (suffix[i*n + j + 1] * currElement) % mod;
            }
        }

        int prefix = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int num = grid[i][j] % mod; 
                grid[i][j] = (prefix * suffix[i*n + j + 1]) % mod;
                prefix = (prefix * num) % mod;
            }
        }

        return grid;
    }
};