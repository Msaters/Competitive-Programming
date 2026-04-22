const int N = 107;

class Solution {
private:
    int diff(string& a, string& b) {
        int result = 0;
        for(int i = 0; i < a.length(); i++) {
            result += (int) (a[i] != b[i]);
        }
        return result;
    }

    bool isQueryWithinTwoFromDictionary(string& query, vector<string>& dictionary) {
        for(string& entry : dictionary) {
            if(diff(query, entry) <= 2) return true; 
        }
        return false;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(int i = 0; i < queries.size(); i++) {
            if(isQueryWithinTwoFromDictionary(queries[i], dictionary)) {
                result.push_back(queries[i]);
            }
        }
        return result;
    }
};