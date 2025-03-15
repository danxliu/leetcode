# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    carry = 0
    l3 = ListNode()
    cur = l3

    while l1 != None or l2 != None or carry:
        cur1 = 0
        cur2 = 0
        if l1:
            cur1 = l1.val
        if l2:
            cur2 = l2.val
        val = cur1 + cur2 + carry
        carry = val//10
        val = val%10
        cur.next = ListNode(val)
        cur = cur.next
        if l1:
            l1 = l1.next
        if l2:
            l2 = l2.next
    return cur.next

