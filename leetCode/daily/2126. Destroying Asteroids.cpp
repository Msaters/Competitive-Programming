class Solution {
public:
    bool asteroidsDestroyed(int currMass, vector<int>& asteroids) {
        long long mass = static_cast<long long>(currMass);
        sort(asteroids.begin(), asteroids.end());
        for(int asteroid : asteroids) {
            if(mass >= asteroid) mass += asteroid;
            else return false;
        }
        return true;
    }
};