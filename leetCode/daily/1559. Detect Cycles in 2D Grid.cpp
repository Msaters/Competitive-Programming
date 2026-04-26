const int max_N = 507;
bool vis[max_N][max_N];

struct point {
    int y, x;

    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const point& other) const {
        return x != other.x || y != other.y;
    }
};



class Solution {
private:
    bool was;
    int m, n;
    void dfs(point v, point p, vector<vector<char>>& grid) {
        if(vis[v.y][v.x]) {
            was = true;
            return;
        }

        vis[v.y][v.x] = true;
        // up
        if(v.y - 1 >= 0 && grid[v.y - 1][v.x] == grid[v.y][v.x] && (p.x != v.x || p.y != v.y - 1)) {
            dfs({v.y - 1, v.x}, v, grid);
        }
        // right
        if(v.x + 1 < n && grid[v.y][v.x + 1] == grid[v.y][v.x] && (p.x != v.x + 1 || p.y != v.y)) {
            dfs({v.y, v.x + 1}, v, grid);
        }
        // down
        if(v.y + 1 < m && grid[v.y + 1][v.x] == grid[v.y][v.x] && (p.x != v.x || p.y != v.y + 1)) {
            dfs({v.y + 1, v.x}, v, grid);
        }
        // left
        if(v.x - 1 >= 0 && grid[v.y][v.x - 1] == grid[v.y][v.x] && (p.x != v.x - 1 || p.y != v.y)) {
            dfs({v.y, v.x - 1}, v, grid);
        }
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vis[i][j] = false;
            }
        }

        printf("%d %d", m, n);
        was = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    dfs({i, j}, {-1, -1}, grid);
                }
            }
        }

        return was;
    }
};