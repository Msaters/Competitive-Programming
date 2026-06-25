int count1[27];
int count2[27];

class Solution {
public:
    bool isAnagram(string s, string t) {
        for(int i = 0; i < 26; i++) {
            count1[i] = 0;
            count2[i] = 0;
        }

        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++) {
            count1[s[i] - 'a']++;
            count2[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(count1[i] != count2[i]) return false;
        }
        return true;
    }
};