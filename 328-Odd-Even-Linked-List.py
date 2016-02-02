# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        evenList = None
        evenListEnd = None
        curPtr = head
        lastPtr = head
        oddEnd = head
        count = 2

        if not head or not head.next:
            return head

        lastPtr = head
        curPtr = head.next

        while curPtr:
            if count % 2 == 0:
                lastPtr.next = curPtr.next

                if evenList:
                    evenListEnd.next = curPtr
                else:
                    evenList = curPtr
                evenListEnd = curPtr
            else:
                oddEnd = curPtr
            count += 1
            lastPtr = curPtr
            curPtr = curPtr.next

        if evenListEnd:
            evenListEnd.next = None
        if oddEnd:
            oddEnd.next = evenList
        else:
            return evenList
        return head

        
