class Solution {
private:
    int numberWaviness(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num%10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        int waviness = 0;
        for(int i = 1; i < digits.size() - 1; i++) {
            if((digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) || (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])) {
                waviness++;
            }
        }
        return waviness;
    }

public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for(num1; num1 <= num2; num1++) {
            waviness += numberWaviness(num1);
        }
        return waviness;
    }
};