public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        List<int[]> tmp = new ArrayList<>();
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] a1, int[] a2) {
                if (a1[0] < a2[0] || (a1[0] == a2[0] && a1[1] > a2[1])) {
                    return 1;
                }
                return -1;
            }
        });
        for(int[] person: people) {
            tmp.add(person[1], person);
        }
        return tmp.toArray(new int[people.length][]);
    }
}
