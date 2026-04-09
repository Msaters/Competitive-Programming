int mod = 1e9 + 7;
const int N = 1e5 + 7;
const int sqr = 320;

int mult[N][sqr];

class Solution {
private:
    long fastExp(long a, long b) {
        if(b == 0) return 1;
        if(b == 1) return a % mod;
        // returns a^b
        long exponent = fastExp(a, b/2) % mod;
        long result = (exponent * exponent) % mod;
        if(b%2) result = (result * a) % mod;
        return result;
    }

    long inverseMod(long a) {
        return fastExp(a, mod - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < sqr; j++) {
                mult[i][j] = 1;
            }
        }

        for(auto query : queries) {
            long l = query[0], r = query[1], k = query[2], v = query[3];
            if(k < sqr) {
                mult[l][k] = ((long) mult[l][k] * v) % mod;
                int firstOutIndex = l + (((r - l) / k) * k) + k;
                if(firstOutIndex < n)
                    mult[firstOutIndex][k] = ((long) mult[firstOutIndex][k] * inverseMod(v)) % mod;
            } else {
                for(l; l <= r; l += k) {
                    nums[l] = ((long) nums[l] * v) % mod;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < sqr; j++) {
                if(i - j >= 0) {
                    mult[i][j] = ((long) mult[i][j] * mult[i-j][j]) % mod;
                }
            }
        }

        long result = -1;
        for(int i = 0; i < n; i++) {
            long multi = 1;
            for(int j = 0; j < sqr; j++) {
                multi = ((long) multi * mult[i][j]) % mod;
            }
            nums[i] = ((long) nums[i] * multi) % mod;

            if(result == -1) {
                result = nums[i];
            } else {
                result ^= nums[i];
            }
        }

        return result;
    }
};