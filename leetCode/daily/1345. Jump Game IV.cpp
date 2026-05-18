const int max_n = 5 * 1e4 + 7;
vector<int> VG[max_n];
bool Vvis[max_n];
bool vis[max_n];

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, int> m;
        int index = 1;
        for(int num : arr) {
            if(!m[num]) {
                m[num] = index;
                VG[index].clear();
                Vvis[index] = false;
                index++;
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            VG[m[arr[i]]].push_back(i);
            vis[i] = false;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = true;

        while(!q.empty()) {
            auto [i, d] = q.front(); q.pop();
            //printf("[%d, %d]\n", i, d);
            if(i == arr.size() - 1) return d;
            d++;

            if(i - 1 > 0 && !vis[i - 1]) {
                vis[i - 1] = true; 
                q.push({i - 1, d});
            }

            if(i + 1 < arr.size() && !vis[i + 1]) {
                vis[i + 1] = true; 
                q.push({i + 1, d});
            }

            if(!Vvis[m[arr[i]]]) {
                Vvis[m[arr[i]]] = true;
                for(int w : VG[m[arr[i]]]) {
                    if(!vis[w]) {
                        vis[w] = true;
                        q.push({w, d});
                    }
                }
            }
        }

        return -1;
    }
};