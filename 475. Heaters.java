public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int maxDist = 0;
        
        for (int house : houses) {
            int index = Arrays.binarySearch(heaters, house);
            if (index < 0) {
                index = -(index + 1);
            } else {
                continue;
            }
            if (index == 0) {
                maxDist = Math.max(maxDist, heaters[0] - house);
            } else if (index == heaters.length) {
                maxDist = Math.max(maxDist, house - heaters[heaters.length - 1]);
            } else {
                maxDist = Math.max(maxDist, Math.min(house - heaters[index - 1], heaters[index] - house));
            }
        }
        return maxDist;
    }
}
