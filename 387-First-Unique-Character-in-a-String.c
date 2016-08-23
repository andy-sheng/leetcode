#define COUNT 0
#define FIRST_POS 1
int firstUniqChar(char* s) {
    int letters[52][2] = {{0,0}};
    int i = 0;
    while(s[i] != '\0') {
        int letter = s[i] - 'A' <= 26 ? s[i] - 'A' : s[i] - 'a' + 26;
        if(letters[letter][COUNT] == 0) letters[letter][FIRST_POS] = i;
        letters[letter][COUNT]++;
        i++;
    }
    int result = -1;
    for(int letter = 0; letter < 52; letter++) {
        if (letters[letter][COUNT] == 1) {
            if(letters[letter][FIRST_POS] < result || result == -1) result = letters[letter][FIRST_POS];
        }
    }
    return result;
}