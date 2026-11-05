constexpr int max_s = 107;
constexpr int max_l = 607;
int dpPrev[max_s][max_s];
int dpCurr[max_s][max_s];
// opt do O(N^2 pamieciowe)

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dpPrev, 0, sizeof(dpPrev));

        const int len = strs.size();
        vector<pair<int, int>> counts(len + 2, {0, 0});

        for (int i = 0; i < strs.size(); i++)
        {
            string& str = strs[i];
            counts[i + 1].first = count(str.begin(), str.end(), '0');
            counts[i + 1].second = count(str.begin(), str.end(), '1');
        }

        for (int i = 1; i <= strs.size(); i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dpCurr[j][k] = dpPrev[j][k];
                    if (j - counts[i].first >= 0 && k - counts[i].second >= 0) 
                    {
                        dpCurr[j][k] = max(dpCurr[j][k], dpPrev[j - counts[i].first][k - counts[i].second] + 1);
                    }
                }
            }

            memcpy(dpPrev, dpCurr, sizeof(dpCurr));
        }

        return dpCurr[m][n];
    }
};