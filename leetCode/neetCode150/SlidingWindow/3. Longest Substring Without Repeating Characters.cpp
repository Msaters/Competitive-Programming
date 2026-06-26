class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastI;

        for(char c : s) lastI[c] = -1;
        int l = 0, longest = 0;
        for(int i = 0; i < s.size(); i++) {
            if(lastI[s[i]] >= l) {
                l = lastI[s[i]] + 1;
            }
            lastI[s[i]] = i;
            longest = max(longest, i - l + 1);
        } 
        return longest;
    }
};