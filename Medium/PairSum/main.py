class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def pairSum(head):
    """
    :type head: Optional[ListNode]
    :rtype: int
    """
    reverse = []
    forward = []

    def revtrav(cur):
        if (cur != None):
            forward.append(cur.val)
            revtrav(cur.next)
            reverse.append(cur.val)
    revtrav(head)
    ans = 0
    for i, j in zip(reverse, forward):
        ans = max(ans, i + j)
    return ans
