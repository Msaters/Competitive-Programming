class Solution {
private:
    bool strEq(string a, string b) {
        if(a.length() != b.length()) return false;
        for(int i = 0; i < a.length(); i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }

    void strShift(string& a) {
        for(int i = 0; i < a.length() - 1; i++) {
            swap(a[i], a[i+1]);
        }
    }

public:
    bool rotateString(string s, string goal) {
        if(strEq(s, goal)) return true;
        for(int i = 0; i < s.length(); i++) {
            strShift(s);
            if(strEq(s, goal)) return true;
        }
        return false;
    }
};