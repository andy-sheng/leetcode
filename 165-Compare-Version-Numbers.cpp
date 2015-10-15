class Solution {
public:
    int getVersion(string &version) {
        string tmp = version;
        int value = 0;
        int length = version.length();
        for (int i = 0; i < length; i++) {
            if (version[i] == '.') {
                version = version.substr(i + 1, length - i - 1);
                return value;
            }
            value = value * 10 + version[i] - '0';
        }
        version = "";
        return value;
    }
    
    int compareVersion(string version1, string version2) {
        while (version1 != "" || version2 != "") {
            int value1 = getVersion(version1);
            int value2 = getVersion(version2);
            if (value1 > value2) {
                return 1;
            } else if(value1 < value2) {
                return -1;
            }
        }
        return 0;
    }
};