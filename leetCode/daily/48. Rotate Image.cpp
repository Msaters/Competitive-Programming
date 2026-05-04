class Solution {
private:
    void swapRotate(vector<vector<int>>& matrix, int i, int j, int n) {
        int& curr  = matrix[i][j];
        int& right = matrix[j][n - 1 - i];
        int& down  = matrix[n - 1 - i][n - 1 - j];
        int& left  = matrix[n - 1 - j][i];

        swap(curr, right);
        swap(curr, left);
        swap(left, down);
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n - 1 - i; j++) {
                swapRotate(matrix, i, j, n);
            }
        }
    }
};