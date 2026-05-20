const int max_n = 57;
bool isInA[max_n];
bool isInB[max_n];

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        for(int i = 0; i <= n; i++) {
            isInA[i] = false;
            isInB[i] = false;
        }

        int currCommonPrefSize = 0;
        vector<int> commonPref(n, 0);
        for(int i = 0; i < n; i++) {
            isInA[A[i]] = true;
            isInB[B[i]] = true;
            if(isInB[A[i]]) currCommonPrefSize++;
            if(A[i] != B[i] && isInA[B[i]]) currCommonPrefSize++;
            commonPref[i] = currCommonPrefSize;
        }

        return commonPref;
    }
}