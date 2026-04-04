class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int up = i-1 >= 0 ? grid[i-1][j] : 0;
                int left = j-1 >= 0 ? grid[i][j - 1] : 0;
                int leftUp = i-1 >= 0 && j-1 >= 0 ? grid[i - 1][j - 1] : 0;

                grid[i][j] += up + left - leftUp;
                if(grid[i][j] <= k) result++;
            }
        }

        return result;
    }
};