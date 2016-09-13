int maxRotateFunction(int* A, int ASize) {
    int s = 0;
    for (int i = 0; i < ASize; i++) s += A[i];
    
    int *f = (int*)malloc(ASize * sizeof(int));
    f[0] = 0;
    for (int i = 0; i < ASize; i++) f[0] += i * A[i];
    
    int maxF = f[0];
    for (int i = 1; i < ASize; i++) {
        f[i] = f[i - 1] + (s - ASize * A[ASize - i]);
        if (maxF < f[i]) maxF = f[i];
    }

    return maxF;
}