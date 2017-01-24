public class Solution {
    public int[] constructRectangle(int area) {
        int[] result = new int[2];
        int difference = Integer.MAX_VALUE;
        for(int w = 1; w <= Math.sqrt(area); ++w) {
            if (area % w == 0) {
                int l = area / w;
                if (l - w <= difference) {
                    difference = l - w;
                    result[0] = l;
                    result[1] = w;
                }
            }
        }

        return result; 
    }
}
