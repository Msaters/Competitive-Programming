bool isIn[10];

class Solution {
private:
    void clear() {
        for(int i = 0; i < 10; i++) isIn[i] = false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(vector<char>& row : board) {
            clear();
            for(char c : row) {
                if(c != '.') {
                    if(isIn[c - '0']) return false;
                    isIn[c - '0'] = true;
                }
            }
        }

        for(int j = 0; j < board.size(); j++) {
            clear();
            for(vector<char>& row : board) {
                char c = row[j];
                if(c != '.') {
                    if(isIn[c - '0']) return false;
                    isIn[c - '0'] = true;    
                }
            }
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                clear();
                for(int k = j*3; k < j*3 + 3; k++) {
                    for(int l = i*3; l < i*3 + 3; l++) {
                        char c = board[l][k];
                        if(c != '.') { 
                            if(isIn[c - '0']) return false;
                            isIn[c - '0'] = true;  
                        }
                    }
                }
            }
        }
        return true;
    }
};