const int N = 1e3 + 7;
pair<int, int> T[N][N];

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first - b.first, a.second - b.second};
}

class Solution {
private:
    pair<int, int> getPair(int i, int j) {
        if(j < 0 || i < 0) {
            return {0, 0};
        }
        return T[i][j];
    }

    pair<int, int> charToPair(char x) {
        if(x == 'X') return {1, 0};
        if(x == 'Y') return {0, 1};
        return {0, 0};
    }

public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pair<int, int> up = getPair(i - 1, j);
                pair<int, int> left = getPair(i, j - 1);
                pair<int, int> leftUp = getPair(i - 1, j - 1);

                T[i][j] = left + up - leftUp + charToPair(grid[i][j]);

                if(T[i][j].first == T[i][j].second && T[i][j].first != 0) result++;
            }
        }

        return result;
    }
};