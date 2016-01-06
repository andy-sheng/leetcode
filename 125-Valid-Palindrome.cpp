class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;
        int i = 0, j = s.length() - 1;
        bool isLetter;
        while (i < j) {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j]))  j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
