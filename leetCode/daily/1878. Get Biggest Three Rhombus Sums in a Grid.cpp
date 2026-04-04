#define f first
#define s second

class Solution {
public:
    int getPossibleSum(vector<vector<int>>& grid, int i, int j, int k, int m, int n) {
        long long res = grid[i][j];
        if(k == 0) return res;

        pair<int, int> upVertex = {i, j};
        pair<int, int> leftVertex = {i + k, j - k};
        pair<int, int> downVertex = {i + 2*k, j};
        pair<int, int> rightVertex = {i + k, j + k};

        if(i + 2*k >= m ||  j - k < 0 || j + k >= n) return -1;
        res = grid[leftVertex.f][leftVertex.s] + grid[downVertex.f][downVertex.s] + grid[rightVertex.f][rightVertex.s] + grid[upVertex.f][upVertex.s];

        //printf("[%d, %d], [%d, %d], [%d, %d], [%d, %d] \n", upVertex.f, upVertex.s, leftVertex.f, leftVertex.s, downVertex.f, downVertex.s, rightVertex.f, rightVertex.s);

        for(int i = 0; i < k-1; i++) {
            upVertex = {upVertex.f + 1, upVertex.s - 1};
            leftVertex = {leftVertex.f + 1, leftVertex.s + 1};
            downVertex = {downVertex.f - 1, downVertex.s + 1};
            rightVertex = {rightVertex.f - 1, rightVertex.s - 1};
            res += grid[leftVertex.f][leftVertex.s] + grid[downVertex.f][downVertex.s] + grid[rightVertex.f][rightVertex.s] + grid[upVertex.f][upVertex.s];
        }

        printf("res: %d\n", res);
        return res;
    } 

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int, std::greater<int>> sums;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int k = 0;
                int possibleSum = 0;
                while((possibleSum = getPossibleSum(grid, i, j, k, m, n)) != -1) {
                    k++;
                    sums.insert(possibleSum);
                }
            }
        }

        vector<int> res;
        auto it = sums.begin();
        for(int i = 0; i < min(3, (int)sums.size()); i++) {
            res.push_back(*it);
            it = next(it, 1);
        }
        return res;
    }
};