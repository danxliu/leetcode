# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = head
        l = 0
        while head:
            l += 1
            head = head.next
        for i in range(l):
            dummy = dummy.next
        return dummy
