const int N = 1e5 + 7;
int closest[N];

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
    int minMirrorPairDistance(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) closest[i] = N;

        int result = N;
        map<int, int> lastSeen;
        for(int i = 1; i <= nums.size(); i++) {
            int currNum = nums[i-1];
            if(lastSeen[currNum] != 0) {
                result = min(result, i - lastSeen[currNum]);
            }

            lastSeen[reverse(currNum)] = i;
        }

        if(result == N) return -1;
        return result;
    }
};