public class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList();
        for (int hour = 0; hour < 12; hour++) {
            int hourLed = hour&1;
            hourLed += hour >> 1 & 1;
            hourLed += hour >> 2 & 1;
            hourLed += hour >> 3 & 1;
            if (hourLed > num) continue;
            for (int minute = 0; minute < 60; minute++) {
                int minuteLed = minute&1;
                minuteLed += minute>>1 & 1;
                minuteLed += minute>>2 & 1;
                minuteLed += minute>>3 & 1;
                minuteLed += minute>>4 & 1;
                minuteLed += minute>>5 & 1;
                if (minuteLed + hourLed == num) {
                    String seperator = minute / 10 != 0 ? ":" : ":0";
                    result.add(hour + seperator + minute);
                } 
            }
        }
        return result;
    }
}