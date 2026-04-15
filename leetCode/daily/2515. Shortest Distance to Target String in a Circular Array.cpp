const int INF = 1e9;

class Solution {
private:
    bool strEqual(string& s1, string& s2) {
        if(s1.length() != s2.length()) return false;
        for(int i = 0; i < s1.length(); i++) 
            if(s1[i] != s2[i]) return false;
        return true;
    }

public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int distRight = INF;
        int distLeft = INF;
        int wordSize = words.size();

        for(int i = 0; i < wordSize; i++) {
            if(strEqual(target, words[i])) {
                if(i == startIndex) {
                    distRight = 0;
                    distLeft = 0;
                }
                
                if(i < startIndex) {
                    distLeft = min(startIndex - i, distLeft);
                    distRight = min(distRight, i + wordSize - startIndex); 
                } 

                if(i > startIndex) {
                    distLeft = min(distLeft, startIndex + 1 + (wordSize - 1 - i));
                    distRight = min(distRight, i - startIndex); 
                } 
            }
        }

        if (min(distLeft, distRight) == INF) return -1; 
        return min(distLeft, distRight);
    }
};