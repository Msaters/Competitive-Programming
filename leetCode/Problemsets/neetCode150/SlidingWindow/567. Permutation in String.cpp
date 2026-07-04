class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> Cs1(26, 0);
        vector<int> Cs2(26, 0);

        for(char c : s1) Cs1[c - 'a']++;
        int unMatched = s1.size();

        for(int i = 0; i < s1.size(); i++) {
            short r = s2[i] - 'a';
            if(Cs1[r] > Cs2[r]) unMatched--;
            Cs2[r]++;
        }

        if(unMatched == 0) return true;

        for(int right = s1.size(); right < s2.size(); right++) {
            short r = s2[right] - 'a', l = s2[right - s1.size()] - 'a';
            //printf("before: r: %c, Cs1: %d, Cs2: %d, l: %c, Cs1: %d, Cs2: %d, unMatched: %d \n", s2[right], Cs1[r], Cs2[r], s2[right - s1.size()], Cs1[l], Cs2[l], unMatched);
            if(Cs2[l] <= Cs1[l]) unMatched++; Cs2[l]--;
            if(Cs1[r] > Cs2[r]) unMatched--; Cs2[r]++; 
            //printf("after: r: %c, Cs1: %d, Cs2: %d, l: %c, Cs1: %d, Cs2: %d, unMatched: %d \n", s2[right], Cs1[r], Cs2[r], s2[right - s1.size()], Cs1[l], Cs2[l], unMatched);

            if(unMatched == 0) return true;
        }
        return false;
    }
};