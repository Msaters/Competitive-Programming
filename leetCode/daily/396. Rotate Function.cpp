class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> T;
        vector<int> pref;
        pref.push_back(0);

        for(int j = 0; j < 2; j++)
            for(int i = 0; i < n; i++) {
                T.push_back(nums[i]);
                pref.push_back(pref[pref.size() - 1] + nums[i]);
            }
        
        int F = 0;
        for(int i = n; i < 2*n; i++) F += T[i] * (i - n);
        int maks = F;

        for(int i = 1; i < n; i++) {
            //printf("F: %d, pref[2*n - i]: %d, pref[n - i]: %d, T[2*n - i]: %d, (n-1): %d\n", F, pref[2*n - i], pref[n - i], T[2*n - i], (n-1));
            F = F + pref[2*n - i] - pref[n - i + 1] - T[2*n - i] * (n-1);
            //cout << F << "\n";
            maks = max(maks, F);
        }

        return maks;
    }
};