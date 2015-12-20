#include <math.h>
int bulbSwitch(int n) {
    int result = 0;
    if (n == 0) {
        return 0;
    }
    n++;
    for(int i = 1; i < n; i++) {
        double limit = sqrt(i);
        if (limit == ceil(limit)) {
            result++;
        }
    }
    return result;
}