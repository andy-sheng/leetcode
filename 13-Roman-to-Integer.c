int getTmpResult(char *s, char str1, char str2  , char str3, int *i, int weight) { // str1 I   str2 V str3 X
    int tmpResult = 0;
    int min = weight / 10;
    int mid = weight>>1;
    while (true) {
        if (s[*i] == str1) {
            tmpResult += weight / 10;
        
        } else if(s[*i] == str2) {
            if (tmpResult != 0) {
                tmpResult = mid - tmpResult;
            } else {
                tmpResult = mid;
            }
 
        } else if(s[*i] == str3){
            tmpResult = weight - min;
            (*i)++;
            return tmpResult;
        } else {
            return tmpResult;
        }
        (*i)++;
    }
    return tmpResult;
}

int romanToInt(char* s) {
    int result = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'I' || s[i] == 'V') { // 1-10
            result += getTmpResult(s, 'I', 'V', 'X', &i, 10);
        } else if(s[i] == 'X' || s[i] == 'L') { // 10-100
            result += getTmpResult(s, 'X', 'L', 'C', &i, 100);
        } else if(s[i] == 'C' || s[i] == 'D'){ // 100-1000
            result += getTmpResult(s, 'C', 'D', 'M', &i, 1000);
        } else {
            result += getTmpResult(s, 'M', 'O', 'P', &i, 10000);
        }
    }
    return result;
}