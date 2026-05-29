class Solution {
public:
    int sumOfDigits(int& n) {
        int resSum = 0;
        while(n) {
            resSum += n%10;
            n /= 10;
        }
        return resSum;
    }
    int minElement(vector<int>& nums) {
        int minElem = 1e9;
        for(int& num : nums) {
            minElem = min(minElem, sumOfDigits(num));
        }
        return minElem;
    }
};