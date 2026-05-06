class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(boxGrid[i][j] == '#') {
                    int k = j;
                    while(k < n - 1 && boxGrid[i][k + 1] == '.') {
                        swap(boxGrid[i][k], boxGrid[i][k + 1]);
                        k++;
                    }
                }
            }
        }

        vector<vector<char>> res(n, vector<char>(m, '#'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = boxGrid[m - j - 1][i];
            }
        }

        return res;
    }
};