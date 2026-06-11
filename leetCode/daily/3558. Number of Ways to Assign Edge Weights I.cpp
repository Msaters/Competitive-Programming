#define ll long long
const ll mod = 1e9 + 7;
const int max_n = 1e5 + 7;

constexpr array<int, max_n> generateOddCountTable() {
    std::array<int, max_n> arr{}; 
    arr[0] = 0;
    ll exp = 1;
    for (int i = 1; i < max_n; ++i) {
        arr[i] = exp;
        exp *= 2;
        exp %= mod; 
    }
    return arr;
}

constexpr array<int, max_n> oddCountForHeights = generateOddCountTable();
vector<int> G[max_n];

class Solution {
private: 
    int getBiggestHight(int v, int p) {
        if(G[v].size() == 1 && v != 1) return 0;
        int biggestHeight = 0;
        for(int w : G[v]) if(w != p) biggestHeight = max(biggestHeight, getBiggestHight(w, v));
        return biggestHeight + 1;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
        }

        for(auto& edge : edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }

        return oddCountForHeights[getBiggestHight(1, 0)];
    }
};