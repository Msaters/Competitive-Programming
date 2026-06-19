class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0, highestAltitude = 0;
        for(int g : gain) {
            currAltitude += g;
            highestAltitude = max(highestAltitude, currAltitude);
        }
        return highestAltitude;
    }
};