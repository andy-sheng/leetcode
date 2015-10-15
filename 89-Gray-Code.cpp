#include <math.h>
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n == 0) {
            result.push_back(0);
        } else {
            vector<int> sub = grayCode(n-1);
            int m = sub.size();
            for (int i = 0; i < m; i++) {
                result.push_back(sub[i]);
            }
            int tmp = pow(2, n - 1);
            for (int i = m - 1; i >= 0; i--) {
                result.push_back(sub[i] + tmp);
            }
        }
        return result;
    }
    
};