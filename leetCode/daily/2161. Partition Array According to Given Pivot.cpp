class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // alg Horea
        int n = nums.size();
        vector<int> pivotVec(n, 0);
        int left = 0, right = n - 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                pivotVec[left] = nums[i];
                left++;
            }

            if(nums[n-1-i] > pivot) {
                pivotVec[right] = nums[n-1-i];
                right--;
            }
        }

        for(; left <= right; left++) {
            pivotVec[left] = pivot;
        }
      
        return pivotVec;
    }
};