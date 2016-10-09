public class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder result = new StringBuilder("");
        int c = 0;
        for(int i = num1.length() - 1, j = num2.length() - 1; true; i--, j--) {
            int tmp;
            if (i > -1 && j > -1) {
                tmp = num1.charAt(i) - '0' + num2.charAt(j) - '0' + c;
            } else if(i > -1) {
                tmp = num1.charAt(i) - '0' + c;
            } else if(j > -1){
                tmp =  num2.charAt(j) - '0' + c;
            } else {
                break;
            }
            if (tmp >= 10) {
                c = 1;
                tmp %= 10;
            } else {
                c = 0;
            }
            result.insert(0, tmp);
        }
        if (c == 1) {
            result.insert(0, '1');
        }
        return result.toString();
    }
}