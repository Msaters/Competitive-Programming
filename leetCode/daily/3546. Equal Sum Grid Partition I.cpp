int m, n;

class Solution {
public:
    bool horizaontalComparison(vector<vector<long>>& leftUp, vector<vector<long>>& rightDown, int j) {
        return leftUp[m][j] == rightDown[1][j+1];
    }

    bool verticalComparison(vector<vector<long>>& leftUp, vector<vector<long>>& rightDown, int i) {
        return leftUp[i][n] == rightDown[i+1][1];
    }

    bool solve(vector<vector<long>>& leftUp, vector<vector<long>>& rightDown) {
        bool result = false;
        for(int i = 1; i < m; i++) {
            result = result || verticalComparison(leftUp, rightDown, i);
        }

        for(int j = 1; j < n; j++) {
            result = result || horizaontalComparison(leftUp, rightDown, j);
        }

        return result;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<long>> leftUp(m+2, vector<long>(n+2, 0));
        vector<vector<long>> rightDown(m+2, vector<long>(n+2, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                leftUp[i][j] = leftUp[i][j - 1] + leftUp[i-1][j] - leftUp[i-1][j-1] + grid[i-1][j-1];
            }
        }

        for(int i = m; i >= 1; i--) {
            for(int j = n; j >= 1; j--) {
                rightDown[i][j] = rightDown[i][j+1] + rightDown[i+1][j] - rightDown[i+1][j+1] + grid[i-1][j-1];
            }
        }

        return solve(leftUp, rightDown);
    }
};