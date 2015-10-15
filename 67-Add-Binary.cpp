class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int n = (a.length() >= b.length()) ? b.length() : a.length();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int flag = 0;
        for (int m = 0; m < n; m++) {
            if (a[i] == '1' && b[j] == '1') {
                if (flag == 0) {
                    result = "0" + result;
                    flag = 1;
                } else {
                    result = "1" + result;
                    flag = 1;
                }
            } else if(a[i] == '1' || b[j] == '1') {
                if (flag == 0) {
                    result = "1" + result;
                } else {
                    result = "0" + result;
                }
            } else {
                if (flag == 0) {
                    result = "0" + result;
                } else {
                    result = "1" + result;
                    flag = 0;
                }
            }
            i--;
            j--;
        }
        string last = (a.length() >= b.length()) ? a : b;
        i = (i > j) ? i : j;
        for (; i >= 0; i--) {
            if (last[i] == '0') {
                if(flag == 0) {
                    result = "0" + result;
                } else {
                    result = "1" + result;
                    flag = 0;
                }
                    
            } else {
                if(flag == 0) {
                    result = "1" + result;
                } else {
                    result = "0" + result;
                    flag = 1;
                }
            }
        }
        if (flag == 1) {
            result = "1" + result;
        }
        
        return result;
    }
};