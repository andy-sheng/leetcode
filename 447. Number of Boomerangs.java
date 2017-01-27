public class Solution {
    private int distanceBetween(int[] a, int[] b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
    
    private int An2(int n) {
        int result = 1;
        for (int i = n - 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    
    public int numberOfBoomerangs(int[][] points) {
        int result = 0;
        int[][] distance = new int[points.length][points.length];
        for (int i = 0; i < points.length; ++i) {
            for (int j = i + 1; j < points.length; ++j) {
                distance[i][j] = distanceBetween(points[i], points[j]);
                distance[j][i] = distance[i][j];
            }
        }
        for (int i = 0; i < points.length; ++i) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int j = 0; j < points.length; ++j) {
                if (distance[i][j] != 0) {
                    if (map.containsKey(distance[i][j])) {
                        map.put(distance[i][j], map.get(distance[i][j]) + 1);
                    } else {
                        map.put(distance[i][j], 1);
                    }
                }
            }
            for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
                if (entry.getValue() > 1) {
                    result += An2(entry.getValue());    
                }
            }
        }
        return result;
    }
}
