bool canConstruct(char* ransomNote, char* magazine) {
    int lettersNeed[60] = {0};
    int lettersHas[60] = {0};
    int i = 0;
    while(ransomNote[i] != '\0') lettersNeed[ransomNote[i++] - 'A']++;
    i = 0;
    while(magazine[i] != '\0') lettersHas[magazine[i++] - 'A']++;
    
    for(i = 0; i < 60; i++) {
        if (lettersNeed[i] > lettersHas[i]) return false;
    }
    return true;
}