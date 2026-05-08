const int N = 1e6 + 7;
const int max_len = 1e5 + 7;
vector<bool> vis(max_len, false);
vector<bool> primeActivated(N, false);
vector<vector<int>> VirtualNodes(N, vector<int>());

vector<int> divs[N];
int precompute = [](){
        divs[1].push_back(1);
        divs[1].push_back(1);
        for(int i = 2; i < N; i++) {
            if(divs[i].empty()) {
                divs[i].push_back(i);
                for(int j = i+i; j < N; j+=i) {
                    divs[j].push_back(i);
                }
            }
        }
        return 0;
}();

class Solution {
private:
    bool isPrime(int i) {
        return divs[i].size() == 1 && divs[i][0] == i;
    }

    void cleanUp(const vector<int>& used_primes) {
        for(int prime : used_primes) {
            primeActivated[prime] = false;
            VirtualNodes[prime].clear();
        }
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vis[i] = false;
        }

        vector<int> used_primes;
        
        for(int i = 0; i < n; i++) {
            for(int primeDivisor : divs[nums[i]]) {
                if(VirtualNodes[primeDivisor].empty()) {
                    used_primes.push_back(primeDivisor);
                }
                VirtualNodes[primeDivisor].push_back(i);
            }
        }


        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = true;
        while(!q.empty()) {
            auto [i, dist] = q.front();
            printf("i: %d, dist: %d\n", i, dist);
            q.pop();
            if(i == n-1) {
                cleanUp(used_primes);
                return dist;
            } 

            if(!vis[i+1]) {
                vis[i+1] = true;
                q.push({i + 1, dist + 1});
            }

            if(i > 0 && !vis[i-1]) {
                vis[i-1] = true;
                q.push({i - 1, dist + 1});
            }
            
            if(isPrime(nums[i]))
                if(!primeActivated[nums[i]]) {
                    primeActivated[nums[i]] = true;
                    for(int u : VirtualNodes[nums[i]]) {
                        if(!vis[u]) {
                            vis[u] = true;
                            q.push({u, dist + 1});
                        }
                    }
                }
            
        }

        return 0;
    }
};