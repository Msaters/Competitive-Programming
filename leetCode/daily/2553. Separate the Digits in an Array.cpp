class Solution {
private:
    void addSeperatedDigits(int num, vector<int>& separatedDigits) {
        stack<int> s;
        while(num) {
            s.push(num % 10);
            num /= 10;
        }

        while(!s.empty()) {
            separatedDigits.push_back(s.top());
            s.pop();
        }
     }

public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> separatedDigits;

        for(int num : nums) {
            addSeperatedDigits(num, separatedDigits);
        }

        return separatedDigits;
    }
};