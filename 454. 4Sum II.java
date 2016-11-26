public class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> ab = new HashMap<>();
        for (int a:A) {
            for (int b:B) {
                int tmp = a + b;
                if (ab.containsKey((Integer)tmp)) {
                    ab.put((Integer)tmp, ab.get((Integer)tmp) + 1);
                } else {
                    ab.put((Integer)tmp, 1);
                }
            }
        }
        Map<Integer, Integer> cd = new HashMap<>();
        for (int c:C) {
            for (int d:D) {
                int tmp = c + d;
                if (cd.containsKey((Integer)tmp)) {
                    cd.put((Integer)tmp, cd.get((Integer)tmp) + 1);
                } else {
                    cd.put((Integer)tmp, 1);
                }
            }
        }
        int result = 0;
        for (Map.Entry<Integer, Integer> entry: ab.entrySet()) {
            if (cd.containsKey(-entry.getKey())) {
                result += entry.getValue() * cd.get(-entry.getKey());
            }
        }
        return result;
    }
}
