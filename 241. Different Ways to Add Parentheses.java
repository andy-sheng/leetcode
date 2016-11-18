public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
       List<Integer> result = new ArrayList<>();
       Integer num = 0;
       for (int i = 0; i < input.length(); ++i) {
           if (input.charAt(i) == '-' || input.charAt(i) == '+' || input.charAt(i) == '*')  {
               List<Integer> lefts = null;
               List<Integer> rights = null;
               lefts = this.diffWaysToCompute(input.substring(0, i));
               rights = this.diffWaysToCompute(input.substring(i + 1, input.length()));
               for (Integer left: lefts) {
                   for (Integer right: rights) {
                        switch (input.charAt(i)) {
                           case '-':
                               result.add(left - right);
                               break;
                           case '+':
                               result.add(left + right);
                               break;
                           case '*':
                               result.add(left * right);
                               break;
                           
                        }
                   }
               }
           } else {
               num = num * 10 + input.charAt(i) - '0';
           }
       }
       if (result.size() == 0) result.add(num);      
                
       return result;
    }
}
