class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for(int l = 0; l < 26; l++) {
            int r = 0, left = k;
            for(int i = 0; i < s.size(); i++) {
                while((left > 0 || s[r] - 'A' == l) && r < s.size()) {
                    res = max(res, r - i + 1);
                    if(s[r] - 'A' != l) left--;
                    r++;
                }
                //printf("i: %d, r: %d, left: %d\n", i, r, left);
                if(s[i] - 'A' != l) left++;
            }
        }

        return res;
    }
};