bool findCrossArea(int n1, int  n2, int m1, int m2, int *a, int *b) {
    if (m1 <= n2) {
        return false;
    }
    if (n1 <= m2) {
        return false;
    }
    if (m2 <= n2 && n2 < m1) {
        if (m1 < n1) {
            *a = m1;
            *b = n2;
            return true;
        } else {
            *a = n1;
            *b = n2;
            return true;
        }
    }
    if (m2 < n1 && n1 <= m1) {
        if (m2 < n2) {
            *a = n1;
            *b = n2;
            return true;
        } else {
            *a = n1;
            *b = m2;
            return true;
        }
    }
    if (n2 <= m2 && n1 >= m1) {
        *a = m1;
        *b = m2;
        return true;
    }
    return false;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int x1,y1,x2,y2, s = 0;
    s = (C - A) * (D - B) + (G - E)*(H - F);
    
    if(!findCrossArea(C, A, G, E, &x2, &x1)) {
        return s;
    }
    if(!findCrossArea(D, B, H, F, &y2, &y1)) {
        return s;
    }
    s -= (x2 - x1)*(y2 - y1);
    return s;
}