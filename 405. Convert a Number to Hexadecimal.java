public class Solution {
    public String toHex(int num) {
        int mask = 15;
        boolean flag = false;
        String[] hex = new String[]{"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        String result = "";
        for (int i = 7; i > -1; --i) {
            int tmp = num >> (4*i) & mask;
            if (tmp != 0) flag = true;
            if (flag) result += hex[tmp];
        }
        return result.length() == 0 ? "0" : result;
    }
}
