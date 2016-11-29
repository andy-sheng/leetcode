public class Solution {
    private int getMajorityLetter(int []hashMap) {
        int result = hashMap.length - 1;
        for (int i = hashMap.length - 2; i >-1; --i) {
            if (hashMap[i] > hashMap[result]) result = i;
        }
        return result;
    }
    
    public int characterReplacement(String s, int k) {
        int []hashMap = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int result = 0;
        int majorityLetter = -1;
        int windowLeft = -1, windowRight = 0; // slide window
        for(; windowRight < s.length(); ++windowRight) { // window grow
            int letter = s.charAt(windowRight) - 'A';
            ++hashMap[letter];
            if (majorityLetter == -1 ||  hashMap[letter] > hashMap[majorityLetter]) {
                majorityLetter = letter;
            }
            while ((windowRight - windowLeft) - hashMap[majorityLetter] > k) { // window need to shrunk
                ++windowLeft;
                --hashMap[s.charAt(windowLeft) - 'A'];
                majorityLetter = this.getMajorityLetter(hashMap); // select a new majority letter
            }
            if (windowRight - windowLeft > result) result = windowRight - windowLeft;
        }
        return result;
        
    }
}
