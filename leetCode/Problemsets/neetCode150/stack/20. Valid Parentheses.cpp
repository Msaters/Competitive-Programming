class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(char c : s) {
            switch(c) {
                case ')':
                    if(p.empty()) return false;
                    if(p.top() != '(') return false;
                    p.pop();
                    break;
                case '}':
                    if(p.empty()) return false;
                    if(p.top() != '{') return false;
                    p.pop();
                    break;
                case ']':
                    if(p.empty()) return false;
                    if(p.top() != '[') return false;
                    p.pop();
                    break;
                default:
                    p.push(c);
            }
        }

        if(!p.empty()) return false;
        return true;
    }
};