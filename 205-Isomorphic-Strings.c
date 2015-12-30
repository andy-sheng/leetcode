bool isIsomorphic(char* s, char* t) {
    bool flag[128] = {0};
    bool transFlag[128] = {0};
    char trans[128] = {'0'};
    for (int i = 0; i < 128; i++) {
        flag[i] = 0;
    }
    int i = 0;
    while (s[i] != '\0' && t[i] != '\0') {
        if (!transFlag[s[i]]) {
            if (flag[t[i]]) {
                return false;
            } else {
                flag[t[i]] = true;
                trans[s[i]] = t[i];
                transFlag[s[i]] = true;
            }
        } else {
            if (trans[s[i]] != t[i]) {
                return false;
            }
        }
        i++;
    }
    return true;
}
