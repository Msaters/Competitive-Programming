#define ll long long
const ll mod = 1e9 + 7;

struct number {
    ll val = 0;
    ll size = 0;
    ll powTen = 1;
    int sumOfDigits = 0;
    number(ll v, ll s, ll pow, int sumDigits) : val(v), size(s), powTen(pow), sumOfDigits(sumDigits) {}
    number(ll digit) : val(digit), sumOfDigits(digit) { powTen = digit == 0 ? 1 : 10; }
    number() = default;
};

const int max_n = 1e5 + 7;
const int max_pow = 17;
const int max_pow_val = 65536; // 2^16
number rangeNum[max_pow][max_n];

class Solution {
private:
    number merge(number& a, number& b) {
        return {(a.val * b.powTen + b.val) % mod, a.size + b.size, (a.powTen * b.powTen) % mod, a.sumOfDigits + b.sumOfDigits};
    }

    int build_ans(int l, int r) {
        number resNum = number();
        int currPowVal = max_pow_val;
        int powI = 16;
        while(currPowVal) {
            if(r - l + 1 >= currPowVal) {
                resNum = merge(resNum, rangeNum[powI][l]);
                l += currPowVal;
            }

            powI--;
            currPowVal /= 2;
        }

        return (resNum.val * resNum.sumOfDigits) % mod;
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            ll digit = s[i] - '0';
            rangeNum[0][i] = number(digit);
        }

        int jump = 1;
        for(int i = 1; i < 17; i++) {
            //printf("\n------ i : %d ------\n", i);
            for(int j = 0; j < n - 2*jump + 1; j++) {
                rangeNum[i][j] = merge(rangeNum[i - 1][j], rangeNum[i - 1][j + jump]);
                //printf("j: %d, rangeNum[i][j]: %d, rangeNum[i - 1][j] : %d, rangeNum[i - 1][j + jump]: %d\n", j, rangeNum[i][j].val, rangeNum[i - 1][j].val, rangeNum[i - 1][j + jump].val);
            }

            jump *= 2;
        }
        
        vector<int> res;
        for(vector<int>& query : queries) {
            res.push_back(build_ans(query[0], query[1]));
        }

        return res;
    }
};