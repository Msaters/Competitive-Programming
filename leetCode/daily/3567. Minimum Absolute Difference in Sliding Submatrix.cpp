const int INF = 1e8;

class Solution {
private:
    int getSum(vector<vector<int>>& grid, vector<int>& elemnts, int i, int j, int k) {
        int idx = 0;
        for(int m = i; m < i + k; m++) {
            for(int l = j; l < j + k; l++) {
                elemnts[idx] = grid[m][l];
                idx++;
            }
        }

        sort(elemnts.begin(), elemnts.end());
        int res = INF;
        for(int i = 1; i < elemnts.size(); i++) {
            if(elemnts[i] - elemnts[i - 1] != 0)
                res = min(res, elemnts[i] - elemnts[i - 1]);
        }

        if(res == INF) res = 0;
        return res;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(m-k+1, vector<int>(n-k+1));
        vector<int> elemnts(k*k);
        for(int i = 0; i < m - k + 1; i ++) {
            for(int j = 0; j < n - k + 1; j++) {
                res[i][j] = getSum(grid, elemnts, i, j, k);
            }
        }

        return res;
    }
};