class Solution {
private:
    void duplicate(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            s.push_back(s[i]);
        }
    }
public:
    string processStr(string s) {
        vector<char> newS;
        for(char znak : s) {
            switch(znak) {
                case '*':
                    if(newS.size()) newS.pop_back();
                    break;
                case '#':
                    if(newS.size()) duplicate(newS);
                    break;
                case '%':
                    if(newS.size()) reverse(newS.begin(), newS.end());
                    break;
                default:
                    newS.push_back(znak);
            }
        }

        string processedS = "";
        for(char znak : newS) {
            processedS += znak;
        }
        return processedS;
    }
};