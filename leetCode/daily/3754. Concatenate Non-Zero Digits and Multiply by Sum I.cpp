class Solution {
public:
    long long sumAndMultiply(int n) {
        long long digitSum = 0;
        long long num = 0;
        long long fact = 1;
        while(n) {
            int digit = n%10;
            n /= 10;
            digitSum += digit;
            num += digit * fact;
            if(digit != 0) fact *= 10;
        }
        return num * digitSum;
    }
};