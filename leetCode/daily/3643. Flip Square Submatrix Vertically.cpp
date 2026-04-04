class Solution {
public:
    void swapRow(vector<vector<int>>& grid, int i, int l, int j, int k) {
        cout << i << " " << l << endl;
        if(i == l) return;
        for(int m = j; m < j + k; m++) {
            swap(grid[i][m], grid[l][m]);
        }
    }

    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = 0; i < k/2; i++) {
            swapRow(grid, x + i, x + k - i - 1, y, k);
        }

        return grid;
    }
};