struct trieNode {
    trieNode* Child[102]{nullptr};
    int index;
    trieNode(int i) : index(i) {};
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        trieNode* head = new trieNode(-1);

        for(string str : strs) {
            vector<int> count(26, 0);
            for(char c : str) {
                count[c - 'a']++;
            }

            trieNode* it = head;
            for(int i = 0; i < 26; i++) {
                if(it->Child[count[i]] == nullptr) {
                    it->Child[count[i]] = new trieNode(-1);
                }
                it = it->Child[count[i]];
                if(i == 25) {
                    if(it->index == -1) {
                        it->index = groups.size();
                        groups.push_back({str});
                    } else {
                        groups[it->index].push_back(str);
                    }
                }
            }
        }

        return groups;
    }
};