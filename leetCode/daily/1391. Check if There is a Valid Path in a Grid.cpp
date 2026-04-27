class Solution {
private:
    bool isConectedRight(int l, int r) {
        switch(l) {
            case 1: return r%2 == 1;
            case 2: return false;
            case 3: return false;
            case 4: return r%2 == 1;
            case 5: return false;
            case 6: return r%2 == 1;
        }
        return false;
    }

    bool isConectedUp(int u, int d) {
        switch(u) {
            case 1: return false;
            case 2: return d == 5 || d == 6 || d == 2;
            case 3: return d == 5 || d == 6 || d == 2;
            case 4: return d == 5 || d == 6 || d == 2;
            case 5: return false;
            case 6: return false;
        }
        return false;
    }

    void dfs(vector<bool>& vis, vector<vector<int>>& G, int v) {
        if(!vis[v]) {
            vis[v] = true;
            for(auto u : G[v]) {
                dfs(vis, G, u);
            }
        }
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> G(90002, vector<int>(0, 0));
        vector<bool> vis(90002, false);

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m - 1) {
                    if(isConectedUp(grid[i][j], grid[i+1][j])) {
                        G[i*n + j].push_back((i+1)*n + j);
                        G[(i+1)*n + j].push_back(i*n + j);
                    }
                }

                if(j < n - 1) {
                    if(isConectedRight(grid[i][j], grid[i][j+1])) {
                        G[i*n + j].push_back(i*n + j + 1);
                        G[i*n + j + 1].push_back(i*n + j);
                    }
                }
            }
        }

        dfs(vis, G, 0);
        return vis[(m-1)*n + n-1];
    }
};