class Solution {
public:
    void stripTrailingSpaces(string& str) {
        int n = str.length() - 1;
        while(n > 0 && str[n] == ' ') {
            str.pop_back();
            n--;
        }
    }

    string decodeCiphertext(string encodedText, int rows) {
        string result = "";
        int n = encodedText.length();
        int rowSize = n / rows;
        for(int j = 0; j < rowSize; j++) {
            for(int i = 0; i < rows; i++) {
                if (j + i*rowSize + i < n) {
                    result += encodedText[j + i*rowSize + i];
                }
            }
        }

        stripTrailingSpaces(result);
        return result;
    }
};