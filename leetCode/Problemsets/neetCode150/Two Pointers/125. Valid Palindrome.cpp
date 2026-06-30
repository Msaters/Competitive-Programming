class Solution {
public:
    bool isPalindrome(string s) {
        string alpha = "";
        for(char c : s) {
            if(c >= 'A' && c <= 'Z') alpha += c - 'A' + 'a';
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) alpha += c;
        }

        int l = 0, r = alpha.size() - 1;
        while(l < r) {
            if(alpha[l] != alpha[r]) return false;
            l++; r--;
        }
        return true;
    }
};