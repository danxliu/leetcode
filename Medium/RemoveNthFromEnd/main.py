# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        res = "List: "
        temp = self
        while not temp is None:
            res += str(temp.val)
            res += " "
            temp = temp.next
        return res


def removeNthFromEnd(head, n):
    """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
    # Get length of linked list
    temp = head
    length = 0
    while not temp is None:
        length += 1
        temp = temp.next
    n = length - n
    cur = head
    if n == 0:
        return head.next
    while not cur is None:
        if n == 1:
            if not cur.next is None:
                cur.next = cur.next.next
            else:
                cur.next = None
            return head
        cur = cur.next
        n -= 1


ll = ListNode(1)
ll.next = ListNode(2)
print(removeNthFromEnd(ll, 2))
