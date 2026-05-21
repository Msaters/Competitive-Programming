class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, bool> m;
        for(int num : arr1) {
            int t = num;
            stack<int> s;
            while(t) {
                s.push(t%10);
                t /= 10;
            }

            while(!s.empty()) {
                t += s.top(); s.pop();
                m[t] = true;
                t *= 10;
            }
        }

        int LCP = 0;
        for(int num : arr2) {
            int t = num;
            stack<int> s;
            while(t) {
                s.push(t%10);
                t /= 10;
            }

            int len = 0;
            while(!s.empty()) {
                len++;
                t += s.top(); s.pop();
                if(m[t] == true) LCP = max(LCP, len);
                t *= 10;
            }
        }

        return LCP;
    }
};