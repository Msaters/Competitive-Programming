#define ll long long
const ll mod = 1e9 + 7;
const int max_n = 2e5 + 7;

const int jumpMax = 18;
int jump[max_n][jumpMax];

vector<int> generateOddCountTable() {
    vector<int> arr(max_n, 0); 
    arr[0] = 0;
    ll exp = 1;
    for (int i = 1; i < max_n; ++i) {
        arr[i] = exp;
        exp *= 2;
        exp %= mod; 
    }
    return arr;
}

vector<int> oddCountForHeights = generateOddCountTable();
vector<int> G[max_n];
int depth[max_n];
int inDeg[max_n];
int outDeg[max_n];
int t = 1;

class Solution {
private: 
    bool isAncestor(int v, int a) {
        return inDeg[v] >= inDeg[a] && outDeg[v] <= outDeg[a];
    }

    int getLCA(int v, int u) {
        //printf("v: %d, in: %d, out: %d, depth: %d\n", v, inDeg[v], outDeg[v], depth[v]);
        //printf("v: %d, in: %d, out: %d, depth: %d\n", u, inDeg[u], outDeg[u], depth[u]);
        //printf("LCAA: %d %d\n", v, u);
        if(isAncestor(u, v)) return depth[u] - depth[v]; 
        int tempV = v;
        for(int i = jumpMax - 1; i >= 0; i--) {
            if((isAncestor(v, jump[v][i]) && isAncestor(u, jump[v][i])) == false) {
                //printf("skok ćwok v: %d, jump[v][i]: %d, u: %d\n", v, jump[v][i], u);
                v = jump[v][i];
            }
        }
        //printf("%d %d %d\n", tempV, u, jump[v][0]);
        //printf("depths: %d %d %d\n", depth[tempV], depth[u], depth[jump[v][0]]);
        return depth[tempV] + depth[u] - 2*depth[jump[v][0]];
    }

    void buildLCA(int v, int p, int d) { 
        depth[v] = d;
        inDeg[v] = t; t++;
        jump[v][0] = p; 
        for(int i = 1; i < jumpMax; i++) {
            jump[v][i] = jump[jump[v][i-1]][i-1];
        }

        for(int w : G[v]) {
            if(w != p) buildLCA(w, v, d + 1);
        }
        outDeg[v] = t; t++;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
        }

        for(auto& edge : edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        outDeg[0] = 1e9;
        t = 1;
        buildLCA(1, 0, 0);

        vector<int> edgeWeights;
        for(auto& query : queries) {
            edgeWeights.push_back(oddCountForHeights[getLCA(query[0], query[1])]);
        }
        return edgeWeights;
    }
};