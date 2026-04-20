class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int result = 0;

        for(int i = 0; i < colors.size(); i++) {
            int j = colors.size() - 1;
            while(j > i) {
                if(colors[i] != colors[j]) {
                    result = max(result, abs(j- i));
                }
                j--;
            }
        }

        return result;
    }
};