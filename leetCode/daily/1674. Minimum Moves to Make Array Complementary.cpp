const long long INF = 1e7;
const long long maxSum = 2e5 + 7; 

class Solution {
public:
    void addMods(vector<long long>& mods, int a, int b, int limit) {
        mods[0] += 2;
        mods[min(a, b) + 1] -= 2;

        mods[min(a, b) + 1] += 1;
        if(min(a, b) + 1 + limit >= max(a, b)) {
            mods[max(a, b) + limit + 1] -= 1;
        } else {
            mods[min(a, b) + 1 + limit + 1] -= 1;
            mods[max(a, b)] += 1;
            mods[max(a, b) + limit + 1] -= 1;

            if(limit * 2 > min(a, b) + 1 + limit) {
                mods[min(a, b) + 1 + limit + 1] += 2;
                if(limit*2 >= max(a, b) - 1) {
                    mods[max(a, b)] -= 2;
                } else {
                    mods[limit*2 + 1] += INF;
                    mods[max(a, b)] -= INF;
                }
            }
        }

        if(limit*2 > max(a, b) + limit) {
            mods[max(a, b) + limit + 1] += 2;
            mods[limit * 2 + 1] += INF;

            int eqMod = INF;
            if(a + b <= limit*2) eqMod = 2;
            if(a + b <= max(a, b) + limit) eqMod = 1;
            mods[a + b] -= eqMod;
            mods[a + b + 1] += eqMod; 
        } else {
            mods[max(a, b) + limit + 1] += INF;

            int eqMod = a + b > max(a, b) + limit ? INF : 1;
            mods[a + b] -= eqMod;
            mods[a + b + 1] += eqMod; 
        }
    }

    int minMoves(vector<int>& nums, int limit) {
        vector<long long> mods(maxSum, 0);
        for(int i = 0; i < nums.size()/2; i++) {
            addMods(mods, nums[i], nums[nums.size() - 1 - i], limit);
        }

        long long res = INF;
        for(int i = 1; i < maxSum; i++) {
            mods[i] += mods[i-1];
            //printf("i: %d, mods: %d\n", i, mods[i]);
            if(i >= 2)
                res = min(res, mods[i]);
        }
        return res;
    }
};