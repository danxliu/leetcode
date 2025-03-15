class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur = ListNode()
        dummy = cur
        hlist = []
        while head:
            hlist = head.val
            head = head.next
        for i in range(len(hlist), -1):
            cur.next = ListNode(hlist[i])
            cur = cur.next
        return dummy.next
