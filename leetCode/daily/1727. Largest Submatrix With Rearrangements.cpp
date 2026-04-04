class Solution {
public:

    int largestSubmatrix(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ones(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) ones[i][j] = matrix[i][j];
                else {
                    ones[i][j] = matrix[i][j] ? ones[i - 1][j] + 1 : 0;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            vector<int> sizes;
            for(int j = 0; j < n; j++) {
                sizes.push_back(ones[i][j]);
            }
            sort(sizes.begin(), sizes.end(), greater<int>());

            for(int j = 0; j < n; j++) {
                res = max(res, (j+1) * sizes[j]);
            }
        }
        return res;

        return 0;
    }
};