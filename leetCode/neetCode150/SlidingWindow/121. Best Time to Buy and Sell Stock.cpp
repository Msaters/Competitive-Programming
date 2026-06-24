class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int maxProf = 0;
        for(int& price : prices) {
            maxProf = max(maxProf, price - currMin);
            currMin = min(currMin, price);
        }
        return maxProf;
    }
};