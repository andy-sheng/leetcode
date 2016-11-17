public class Solution {
    public String originalDigits(String s) {
        String result = "";
        int []map = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int []store = {0,0,0,0,0,0,0,0,0,0};
        
        for (int i = s.length() - 1; i > -1; --i) {
            ++map[s.charAt(i) - 'a'];
        }
        // count zero  by z
        store[0] = map['z' - 'a'];
        map['e' - 'a'] -= map['z' - 'a'];
        map['r' - 'a'] -= map['z' - 'a'];
        map['o' - 'a'] -= map['z' - 'a'];
        map['z' - 'a'] = 0;
        
        // count six by x
        store[6] = map['x' - 'a'];
        map['i' - 'a'] -= map['x' - 'a'];
        map['s' - 'a'] -= map['x' - 'a'];
        map['x' - 'a'] = 0;
        
        // count seven by s
        store[7] = map['s' - 'a'];
        map['e' - 'a'] -=  map['s' - 'a'] * 2;
        map['v' - 'a'] -= map['s' - 'a'];
        map['s' - 'a'] = 0;
        
        // count five by v
        store[5] = map['v' - 'a'];
        map['f' - 'a'] -= map['v' - 'a'];
        map['i' - 'a'] -= map['v' - 'a'];
        map['e' - 'a'] -= map['v' - 'a'];
        map['v' - 'a'] = 0;
        
        // count four by f
        store[4] = map['f' - 'a'];
        map['o' - 'a'] -= map['f' - 'a'];
        map['u' - 'a'] -= map['f' - 'a'];
        map['r' - 'a'] -= map['f' - 'a'];
        map['f' - 'a'] = 0;
        
        // count three by r
        store[3] = map['r' - 'a'];
        map['h' - 'a'] -= map['r' - 'a'];
        map['t' - 'a'] -= map['r' - 'a'];
        map['e' - 'a'] -= map['r' - 'a'] * 2;
        map['r' - 'a'] = 0;
        
        // count eight by h
        store[8] = map['h' - 'a'];
        map['e' - 'a'] -= map['h' - 'a'];
        map['i' - 'a'] -= map['h' - 'a'];
        map['g' - 'a'] -= map['h' - 'a'];
        map['t' - 'a'] -= map['h' - 'a'];
        map['h' - 'a'] = 0;
         
        // count two by t
        store[2] = map['t' - 'a'];
        map['w' - 'a'] -= map['t' - 'a'];
        map['o' - 'a'] -= map['t' - 'a'];
        map['t' - 'a'] = 0;
        
        // count one by o
        store[1] = map['o' - 'a'];
        map['n' - 'a'] -= map['o' - 'a'];
        map['e' - 'a'] -= map['o' - 'a'];
        map['o' - 'a'] = 0;
        
        // count nine by i
        store[9] = map['i' - 'a'];
        map['n' - 'a'] -= map['i' - 'a'];
        map['e' - 'a'] -= map['i' - 'a'];
        map['i' - 'a'] = 0;
        
        for (int i = 0; i < store.length; ++i) {
            for (int j = 0; j < store[i]; ++j) {
                result += i;
            }
        }
        return result;
    }
}
