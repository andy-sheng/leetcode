#include <math.h>
class Solution {
public:
   bool isPalindrome(ListNode* head) {
       if (!head) return true;
       int length = 0, flag, mid;
       ListNode* forward = head, *backward = head;
       while (forward) {
           forward = forward->next;
           length++;
       }
       mid = ceil(length * 1.0 / 2);
       flag = length % 2;
       forward = head;
       ListNode* forwardTmp = forward->next;
       while (mid > 1) {
           mid--;
           cout<<"forward:"<<forward->val<<endl;
           backward = forward;
           forward = forwardTmp;
           forwardTmp = forwardTmp->next;
           forward->next = backward;
       }
       if (!flag) {
           backward = forward;
       }
       forward = forwardTmp;
       while(forward) {
           if (forward->val != backward->val) return false;
           forward = forward->next;
           backward = backward->next;
       }
       return true;
   }
};
