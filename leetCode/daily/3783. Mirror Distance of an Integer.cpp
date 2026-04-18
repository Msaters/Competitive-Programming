class Solution {
private:
    int reverse(int a) {
        int result = 0;
        while(a) {
            result *= 10;
            result += a%10;
            a /= 10;
        }
        return result;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};