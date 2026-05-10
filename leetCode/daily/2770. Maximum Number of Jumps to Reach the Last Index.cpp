const int max_N = 1007;
vector<int> G[max_N];

const int INF = 1e9;
int dp[max_N];
int dfs(int v, int n) {
    if(dp[v] != -INF) return dp[v];
    if(v == n - 1) return dp[v] = 0;
    if(G[v].empty()) return dp[v] = -INF;
    for(int w : G[v]) {
        dp[v] = max(dp[v], dfs(w, n));
    }
    dp[v] += 1;
    return dp[v];
}

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            G[i].clear();
            dp[i] = -INF;
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[j] - nums[i]) <= target) {
                    G[i].push_back(j);
                    //printf("[%d, %d] val: [%d, %d]\n", i, j, nums[i], nums[j]);
                }
            }
        }

        dfs(0, n);
        if(dp[0] < 0) return -1;
        return dp[0];
    }
};