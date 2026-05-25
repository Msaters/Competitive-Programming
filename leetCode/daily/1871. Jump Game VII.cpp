const int INF = 1e9;
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // bfs in O(n)
        int n = s.size();
        if(s[n - 1] != '0') return false;
        queue<int> q;
        q.push(0);

        int prev = -INF;
        while(!q.empty()) {
            int i = q.front(); q.pop();
            int prevMaxJump = min(prev + maxJump, n - 1);
            for(int j = max(prevMaxJump + 1, i + minJump); j <= min(i + maxJump, n - 1); j++) {
                if(s[j] == '0') {
                    if(j == n - 1) return true;
                    q.push(j);
                }
            }
            prev = i;
        }

        return false;
    }
};