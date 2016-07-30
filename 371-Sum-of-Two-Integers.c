int getSum(int a, int b) {
    int go = 1;
    int position = 1;
    int result = 0;
    int c = 0;
    
    int a1 =  a & 1;
    int b1 = b & position;
    while (go) {
        a1 = a & 1;
        b1 = b & 1;
        if (a1 ^ b1 ^ c)
            result = result | position;
        c = a1 & b1 || a1 & c || b1 & c;
        position = position << 1;
        a = a >> 1;
        b = b >> 1;
        go = go << 1;
        
    }
    if  (c)
        return result | position;

    return result;
}