static const int N = 1e5 + 7;
int rowFlat[N];
int colFlat[N];
int m, n;
long long suma = 0;

int occurancesLeft[N];
int occurancesRight[N];


bool isSumEqualDiscounted(int T[], int mid, long long currSum, int notConnectedSection = 0, int chunk = 0) {
    long long rightSum = suma - currSum;
    if(currSum == rightSum) return true;
    
    if(notConnectedSection == 3) {
        return (currSum - T[0] == rightSum) || (currSum - T[mid - 1] == rightSum) || (currSum == rightSum - T[m*n - 1]) || (currSum == rightSum - T[mid]);
    }

    if(notConnectedSection == 1 && currSum > rightSum) {
        return (currSum - T[0] == rightSum) || (currSum - T[chunk - 1] == rightSum);
    }
    
    if(notConnectedSection == 2 && currSum < rightSum) {
        return (currSum == rightSum - T[m*n - 1]) || (currSum == rightSum - T[m*n - chunk]);
    }

    if(currSum > rightSum) {
        long long x = currSum - rightSum;
        if(x >= N) return false;
        return occurancesLeft[x];
    } else {
        long long x = rightSum - currSum;
        if(x >= N) return false;
        return occurancesRight[x];
    }
}

bool solveVertical() {
    // vertical
    long long rowSum = 0;
    for(int i = 0; i < m - 1; i++) {
        for(int j = 0; j < n; j++) {
            occurancesLeft[rowFlat[i*n +j]]++;
            occurancesRight[rowFlat[i*n +j]]--;
            rowSum += rowFlat[i*n + j];
        }

        int mid = (i+1) * n;
        if(m <= 2 || n == 1) {
            if(isSumEqualDiscounted(rowFlat, mid, rowSum, 3, n)) return true;
        } 
        else 
            if(i == 0) {
                if(isSumEqualDiscounted(rowFlat, mid, rowSum, 1, n)) return true;
            } 
            else {
                if(i == m-2) {
                    if(isSumEqualDiscounted(rowFlat, mid, rowSum, 2, n)) return true;
                } else {
                    if(isSumEqualDiscounted(rowFlat, mid, rowSum)) return true;
                }
            }
    }

    return false;
}

bool solveHorizontal() {
    // horizontal
    long long colSum = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            occurancesLeft[colFlat[i*m +j]]++;
            occurancesRight[colFlat[i*m +j]]--;
            colSum += colFlat[i*m + j];
        }

        int mid = (i+1) * m;
        if(n <= 2 || m == 1) {
            if(isSumEqualDiscounted(colFlat, mid, colSum, 3, m)) return true;
        } 
        else 
        if(i == 0) {
            if(isSumEqualDiscounted(colFlat, mid, colSum, 1, m)) return true;
        }
        else {
            if(i == n - 2) {
                if(isSumEqualDiscounted(colFlat, mid, colSum, 2, m)) return true;
            } 
            else {
                if(isSumEqualDiscounted(colFlat, mid, colSum)) return true;
            }
        }
    }

    return false;
}

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        suma = 0;

        for(int i = 0; i < N; i++) {
            occurancesRight[i] = 0;
            occurancesLeft[i] = 0;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                occurancesRight[grid[i][j]]++;
                suma += grid[i][j];
                rowFlat[i*n + j] = grid[i][j];
            }
        }

        if(solveVertical()) return true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                occurancesRight[grid[i][j]] = 0;
                occurancesLeft[grid[i][j]] = 0;
            }
        }

        

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                colFlat[i*m + j] = grid[j][i];
                occurancesRight[grid[j][i]]++;
            }
        }



        return solveHorizontal();
    }

};