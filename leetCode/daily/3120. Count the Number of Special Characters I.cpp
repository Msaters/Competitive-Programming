const int N = 27;
bool lowerCase[N];
bool upperCase[N];

class Solution {
private:
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }

public:
    int numberOfSpecialChars(string word) {
        for(int i = 0; i < N; i++) {
            lowerCase[i] = false;
            upperCase[i] = false;
        }

        for(char c : word) {
            if(isUpper(c)) {
                upperCase[c - 'A'] = true;
            }
            if(isLower(c)) {
                lowerCase[c - 'a'] = true;
            }
        }

        int counter = 0;
        for(int i = 0; i < N; i++) {
            if(lowerCase[i] == upperCase[i] && upperCase[i]) counter++;
        }
        return counter;
    }
};