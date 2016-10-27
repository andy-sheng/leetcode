public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result= new ArrayList<Integer>();
        int[] letters = new int[26];
        int[] tmp = new int[26];
        for (int i = 0; i < 26; i++) {
            letters[i] = 0;
            tmp[i] =0;
        }

        for (int i = 0; i < p.length(); i++) {
            letters[p.charAt(i) - 'a']++;
            tmp[p.charAt(i) - 'a']++;
        }

        int ptrInS = 0;
        while (true) {
            if (ptrInS == s.length()) return result;
            int count = p.length();
            while (count > 0) {
                if (tmp[s.charAt(ptrInS) - 'a'] > 0) {
                    tmp[s.charAt(ptrInS) - 'a']--;
                    ptrInS++;
                    count--;
                } else if (letters[s.charAt(ptrInS) - 'a'] == 0) {
                    ptrInS++;
                    break;
                } else {
                    ptrInS = ptrInS - (p.length() - count) + 1;
                    break;
                }
                if (ptrInS == s.length()) break;
            }
            for (int i = 0; i < 26; i++) tmp[i] = letters[i];
            if (count == 0) {
                result.add(ptrInS - p.length());
                while(ptrInS < s.length() && s.charAt(ptrInS) == s.charAt(ptrInS - p.length())) 
                    result.add(++ptrInS - p.length());
                ptrInS -= p.length() - 1;
            }
        }
    }
}