char* reverseVowels(char* s) {
    int length = 0;
    while(s[length] != '\0') length++;
    
    int front = 0, back = length - 1;
    while (true) {
        while(front < length && s[front] != 'a'
                             && s[front] != 'A' 
                             && s[front] != 'e'
                             && s[front] != 'E'
                             && s[front] != 'i'
                             && s[front] != 'I'
                             && s[front] != 'o'
                             && s[front] != 'O'
                             && s[front] != 'u'
                             && s[front] != 'U') front++;
        while(back > 0 && s[back] != 'a'
                       && s[back] != 'A'
                       && s[back] != 'e'
                       && s[back] != 'E'
                       && s[back] != 'i'
                       && s[back] != 'I'
                       && s[back] != 'o'
                       && s[back] != 'O'
                       && s[back] != 'u'
                       && s[back] != 'U') back--;
        if (front > length || back <= 0 || front >= back) return s;
        char tmp = s[front];
        s[front] = s[back];
        s[back] = tmp;
        front++;
        back--;
    }
}