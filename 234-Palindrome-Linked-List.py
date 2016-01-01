import math
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True
        length = 0
        forward = head
        backward = head
        while forward:
            forward = forward.next
            length += 1
        mid = math.ceil(length * 1.0 / 2)
        flag = length % 2 # 0 means lenght is even 1 means odd

        forward = head
        forwardTmp = forward.next
        while mid > 1: # stop when mid is 0
            mid -= 1;
            backward = forward
            forward = forwardTmp
            forwardTmp = forwardTmp.next
            forward.next = backward

        if not flag:
            backward = forward
        forward = forwardTmp

        while(forward):
            if forward.val != backward.val:
                return False
            forward = forward.next;
            backward = backward.next;
        return True
