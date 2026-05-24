const int max_N = 1007;
vector<int> G[max_N];
int dp[max_N];

class Solution {
    int dfs(int v) {
        if(dp[v] != -1) return dp[v];
        if(!G[v].size()) return 1;
        for(int u : G[v]) {
            dp[v] = max(dp[v], dfs(u) + 1);
        }
        return dp[v];
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        for(int i = 0; i <= n; i++) {
            G[i].clear();
            dp[i] = -1;
        }

        for(int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            while(l >= 0 && abs(i-l) <= d && arr[i] > arr[l]) {
                G[i].push_back(l);
                l--;
            }

            while(r < n && abs(i-r) <= d && arr[i] > arr[r]) {
                G[i].push_back(r);
                r++;
            }
        }

        int maxIndicesToJump = 0;
        for(int i = 0; i < n; i++) maxIndicesToJump = max(maxIndicesToJump, dfs(i));

        return maxIndicesToJump;
    }
};