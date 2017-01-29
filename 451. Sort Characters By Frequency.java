public class Solution {
    public String frequencySort(String s) {
        Map<Integer, Integer> map = new HashMap();
        
        for (int i = 0; i < s.length(); ++i) {
            if (map.containsKey(s.charAt(i) - 'a')) {
                map.put(s.charAt(i) - 'a', map.get(s.charAt(i) - 'a') + 1);
            } else {
                map.put(s.charAt(i) - 'a', 1);
            }
        }
        
        TreeSet<Integer[]> set = new TreeSet<Integer[]>(new Comparator<Integer[]>() {
            public int compare(Integer[] o1, Integer[] o2) {
                if (o1[1] < o2[1]) return 1;
                return -1;
            }
        });
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            set.add(new Integer[]{entry.getKey(), entry.getValue()});
        }
        
        Iterator it = set.iterator();
        StringBuilder builder = new StringBuilder();
        while (it.hasNext()) {
            Integer[] node = (Integer[])it.next();
            for (int i = 0; i < node[1]; ++i)
                builder.append((char)(node[0] + 'a'));
        }
        return builder.toString();
    }
}
