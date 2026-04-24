class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, S = 0;
        for(char c : moves) {
            if(c == 'L') L++;
            if(c == 'R') R++;
            if(c == '_') S++;
        }
        return abs(L-R) + S;
    }
};