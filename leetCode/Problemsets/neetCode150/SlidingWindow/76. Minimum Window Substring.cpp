class Solution {
public:
    string minWindow(string& s, string& t) {
        vector<int> Ct(256, 0);
        vector<int> Cs(256, 0);
        for(char c : t) Ct[c]++;
        
        int minDist = s.size() + 3;
        pair<int, int> resI;
        int l = 0, r = 0, unMatched = t.size();
        while(r < s.size()) {
            // setting right edge
            while(unMatched != 0 && r < s.size()) {
                short c = s[r];
                if(Cs[c] < Ct[c]) unMatched--;
                Cs[c]++; r++;
            }   

            // setting left edge
            while(unMatched == 0) {
                short c = s[l];
                if(minDist > r - l) {
                    minDist = r - l;
                    resI = {l, r};
                }
                if(Cs[c] <= Ct[c]) unMatched++;
                Cs[c]--; l++;
            }
        }

        string res;
        for(int i = resI.first; i < resI.second; i++) res += s[i];
        return res;
    }
};