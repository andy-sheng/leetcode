char findTheDifference(char* s, char* t) {
    int hashMap[26] = {0};
    int i = 0;
    while (s[i] != '\0') hashMap[s[i++] - 'a']++;
    i = 0;
    while (t[i] != '\0') hashMap[t[i++] - 'a']--;
    i = 0;
    while (hashMap[i] == 0) i++;
    return 'a' + i;
}