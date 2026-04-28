class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;

        int mod = grid[0][0] % x;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] % x != mod) return -1;
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(), v.end());
        int val = v[v.size() / 2];
        int result = 0;
        for(int i = 0; i < v.size(); i++) {
            result += abs(val - v[i]) / x;
        }
        return result;
    }
};