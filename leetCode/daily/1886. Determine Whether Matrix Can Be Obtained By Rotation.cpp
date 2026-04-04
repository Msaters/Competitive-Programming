class Solution {
public:

    void rotateRowIntoColumn(vector<vector<int>>& mat, vector<vector<int>>& target, int i) {
        int n = mat.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) { 
                target[i][j] = mat[j][n - 1 - i];
            }
        }
    }

    bool equals(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

    void rotateMatBy90Degree(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < mat.size(); i++) {
            rotateRowIntoColumn(mat, target, i);
        }
    }

    bool checkIfRotationDiff(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> RotationMat(n, vector<int>(n));
        for(int i = 0; i < 4; i++) {
            if(equals(mat, target)) return true;
            rotateMatBy90Degree(mat, RotationMat);
            mat = RotationMat;
        }

        return false;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        return checkIfRotationDiff(mat, target);
    }
};