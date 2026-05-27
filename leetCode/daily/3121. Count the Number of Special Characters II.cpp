const int n = 27;
int lower_case[n];
int upper_case[n];


class Solution {
public:
    int numberOfSpecialChars(string word) {
        for(int i = 0; i < n; i++) {
            lower_case[i] = -1;
            upper_case[i] = -1;
        }

        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(c >= 'a' && c <= 'z') lower_case[c - 'a'] = i;
            if(c >= 'A' && c <= 'Z' && upper_case[c - 'A'] == -1) upper_case[c - 'A'] = i;
        }

        int specialCount = 0;
        for(int i = 0; i < n; i++) {
            specialCount += lower_case[i] < upper_case[i] && lower_case[i] != -1;
        }
        return specialCount;
    }
};