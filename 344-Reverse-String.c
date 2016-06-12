char* reverseString(char* s) {
    int length = 0;
    while(s[length] != '\0') length++;
    
    int head = 0, tail = length - 1;
    char tmp;
    while (head < tail) {
        tmp = s[head];
        s[head] = s[tail];
        s[tail] = tmp;
        ++head;
        --tail;
    }
    return s;
}