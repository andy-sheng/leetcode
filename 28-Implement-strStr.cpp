class Solution {
public:
    void getNext(string p, int next[]) {
        int pLen = p.length();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < pLen - 1) {
            if (k == -1 || p[j] == p[k]) {
                ++k;
                ++j;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
    }
    int strStr(string haystack, string needle) {
        int next[100000];
        getNext(needle, next);
        int i = haystack.length(), j = needle.length(), n = 0, m = 0;
        while (n < i && m < j) {
            if (m == -1 || haystack[n] == needle[m]) {
                n++;
                m++;
            } else {
                m = next[m];
            }
        }
        if (m == j) {
            return n - m;
        } else {
            return -1;
        }
    }
};
