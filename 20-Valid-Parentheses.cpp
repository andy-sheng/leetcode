class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        stack<char> stack;
        stack.push('1');
        for (int i = 0; i < length; i++) {
            if (s[i] == ')') {
                if (stack.top() != '(') {
                    return false;
                }
                stack.pop();
            } else if(s[i] == ']') {
                if (stack.top() != '[') {
                    return false;
                }
                stack.pop();
            } else if(s[i] == '}') {
                if (stack.top() != '{') {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }
        if (stack.size() == 1) {
            return true;
        } else {
            return false;
        }
    }
};
