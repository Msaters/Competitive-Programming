const int N = 1e5 + 7;
int lastAppear[N];
int lastSameAppear[N];

class Solution {
private:
    int getDistance(vector<int>& nums, int k) {
        int j = lastSameAppear[k];
        if(j == -1) return -1;
        int i = lastSameAppear[j];
        if(i == -1) return -1;
        return abs(k-j) + abs(j-i) + abs(k-i);
    }
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            lastAppear[i] = -1;
            lastSameAppear[i] = -1;
        }

        int result = -1;
        for(int i = 0; i < n; i++) {
            lastSameAppear[i] = lastAppear[nums[i]]; 
            if(getDistance(nums, i) != -1)
                if(result == -1)
                    result = getDistance(nums, i);
                else 
                    result = min(result, getDistance(nums, i));
            lastAppear[nums[i]] = i;
        }
        return result;
    }
};


