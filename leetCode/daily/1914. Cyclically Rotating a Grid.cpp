class Solution {
private:
    int size(int m, int n, int i) {
        return 2 * (n - 2*i) + 2 * (m - 2*i) - 4;
    }

    void cyclicRotation(int i, int m, int n, int k, vector<vector<int>>& grid) {
        int s = size(m, n, i);
        k %= s;

        for(int x = 0; x < k; x++) {
            // up
            for(int a = i + 1; a < n - i; a++) {
                //printf("u [%d, %d], [%d, %d]\n", i, a-1, i, a);
                swap(grid[i][a - 1], grid[i][a]);
            }

            // right
            for(int a = i + 1; a < m - i; a++) {
                //printf("r [%d, %d], [%d, %d]\n", a, n - i - 1, a - 1, n - i - 1);
                swap(grid[a][n - i - 1], grid[a - 1][n - i - 1]);
            }

            // down
            for(int a = n - i - 1; a > i; a--) {
                //printf("d [%d, %d], [%d, %d]\n", m - i - 1, a-1, n - i - 1, a);
                swap(grid[m - i - 1][a - 1], grid[m - i - 1][a]);
            }

            // left
            for(int a = m - i - 1; a > i + 1; a--) {
                //printf("l [%d, %d], [%d, %d]\n", a, i, a - 1, i);
                swap(grid[a][i], grid[a - 1][i]);
            }
        }
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int i = 0;
        while(i < m/2 && i < n/2) {
            cyclicRotation(i, m, n, k, grid);
            i++;
        }

        return grid;
    }
};