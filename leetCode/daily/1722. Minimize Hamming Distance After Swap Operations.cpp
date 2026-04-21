const int N = 1e5 + 7;
bool vis[N];
int component[N];

class Solution {
private:
    void markComponentDfs(int v, int mark, vector<int>* G, map<pair<int,int>, int>& M, vector<int>& source) {
        M[{mark, source[v]}]++;
        vis[v] = true;
        component[v] = mark;
        for(int w : G[v]) {
            if(!vis[w]) {
                markComponentDfs(w, mark, G, M, source);
            }
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> G[N];
        map<pair<int,int>, int> M;

        for(int i = 0; i < N; i++) vis[i] = false;

        for(const vector<int>& swap : allowedSwaps) {
            int v = swap[0], u = swap[1];
            G[v].push_back(u);
            G[u].push_back(v);
        }
        
        int componentI = 1;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                markComponentDfs(i, componentI, G, M, source);
                componentI++;
            }
        }

        int result = 0;
        for(int i = 0; i < n; i++) {
            //printf("i: %d, component[i]: %d, target[i]: %d, M[{component[i], target[i]}]: %d\n", i, component[i], target[i], M[{component[i], target[i]}]);
            if(M[{component[i], target[i]}] == 0) {
                result++;
            } else {
                M[{component[i], target[i]}]--;
            }
        }
        return result;
    }
};