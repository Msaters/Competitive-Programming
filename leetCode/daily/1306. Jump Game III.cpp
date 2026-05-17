const int max_n = 1e5;
bool vis[max_n];
bool wasZero;

class Solution {
private:
    void dfs(int v, vector<int>& arr) {
        if(!vis[v]) {
            if(arr[v] == 0) wasZero = true;
            vis[v] = true;
            int right = v + arr[v];
            int left = v - arr[v];
            if(right < arr.size() && !vis[right]) dfs(right, arr);
            if(left >= 0 && !vis[left]) dfs(left, arr);
        }
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        for(int i = 0; i < n; i++) vis[i] = false;
        wasZero = false;
        dfs(start, arr);
        return wasZero;
    }
};