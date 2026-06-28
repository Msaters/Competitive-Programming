#define ll long long

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll, bool> vis;
        unordered_map<ll, int> m;
        for(int num : nums) {
            m[num]++;
            vis[num] = false;
        }


        sort(nums.begin(), nums.end());
        ll maxLen = 0;
        if(m[1] > 0) maxLen = m[1]%2 == 0 ? m[1] - 1 : m[1];

        for(ll num : nums) {
            ll currLen = 0;
            //cout << num << " " << vis[num] << endl;
            while(!vis[num] && m[num]) {
                vis[num] = true;
                
                if(m[num] == 1) {
                    //cout << num << " " << m[num] << " " << currLen << endl;
                    maxLen = max(maxLen, 2*currLen + 1);
                    currLen = 0;
                } 
                else {
                    //cout << num << " " << m[num] << " " << currLen << endl;
                    maxLen = max(maxLen, 2*currLen + 1);
                    currLen++;

                }
                num *= num;
            }
        }
        
        return maxLen;
    }
};