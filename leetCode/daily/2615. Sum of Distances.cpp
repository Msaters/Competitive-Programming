struct e {
    long long count, dist;
};


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<e> left(nums.size() + 7, {0, 0});
        vector<e> right(nums.size() + 7, {0, 0});
        unordered_map<int, int> leftOccurances;
        unordered_map<int, int> rightOccurances;

        for(int i = 0; i < nums.size(); i++) {
            int lastOccur = leftOccurances[nums[i]];
            if(lastOccur) {
                left[i+1] = {left[lastOccur].count, left[lastOccur].dist + abs((i+1) - lastOccur) * left[lastOccur].count};
            }
            leftOccurances[nums[i]] = i+1;
            left[i+1].count++;
        }

        for(int i = nums.size() - 1; i >= 0; i--) {
            int lastOccur = rightOccurances[nums[i]];
            if(lastOccur) {
                right[i+1] = {right[lastOccur].count, right[lastOccur].dist + abs((i+1) - lastOccur) * right[lastOccur].count};
            }
            rightOccurances[nums[i]] = i+1;
            right[i+1].count++;
        }

        vector<long long> res;
        for(int i = 0; i < nums.size(); i++) {
            res.push_back(left[i+1].dist + right[i+1].dist);
        }
        return res;
    }
};