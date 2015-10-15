bool isAnagram(char* s, char* t) {
    int flag[26] = {0};
    for(int i = 0; s[i] !='\0'; i++) {
        flag[s[i] - 'a']++;
    }
    for(int i = 0; t[i] !='\0'; i++) {
        flag[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if(flag[i] != 0) {
            return false;
        }
    }
    return true;
}