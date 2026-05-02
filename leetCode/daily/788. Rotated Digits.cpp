class Solution {
private:
    bool isGood(int x) {
        bool was = false;
        //print("\nisGood z x %d\n", x);
        while(x) {
            int d = x%10;
            //printf("x: %d, d: %d\n", x, d);
            if(d == 3 || d == 4 || d == 7) return false;
            if(d == 2 || d == 5 || d == 6 || d == 9) was = true;
            x /= 10;
        }
        return was;
    }

public:
    int rotatedDigits(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            //printf("i: %d, isGood(i): %d\n", i, isGood(i));
            res += static_cast<int>(isGood(i));
        }
        return res;
    }
};