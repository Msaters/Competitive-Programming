const int mod = 26;
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string mapedWord = "";
        for(string& word : words) {
            int newChar = 0;
            for(char& letter : word) {
                newChar += weights[letter - 'a'];
            }
            newChar %= mod;
            mapedWord += static_cast<char>((mod - 1) - newChar + 'a');
        }

        return mapedWord;
    }
};