public class Solution {
    public int findComplement(int num) {
        int result = 0;
        int pos = 31;
        while((num & (1 << pos)) == 0) --pos;
       
        while(pos >= 0) {
            if ((num & (1<<pos)) == 0) {
                
                result += 1 << pos;
            }
            --pos;
        }
        return result;
    }
}
