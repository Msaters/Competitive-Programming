class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int result = 0, i = 0, j = 0;

        for(i; i < nums1.size(); i++) {
            while(j < i) j++;
            if(j >= nums2.size()) break;
            while(j + 1 < nums2.size() && nums1[i] <= nums2[j+1]) {
                j++;
                result = max(result, j - i);
            }
        }

        return result;
    }
};