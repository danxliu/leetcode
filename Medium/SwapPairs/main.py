# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        res = "List: "
        cur = self
        while not cur is None:
            res += str(cur.val)
            res += " "
            cur = cur.next
        return res


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # cur: 0 -> 1 -> 2 -> 3 -> 4

        dummy = ListNode(0, head)
        prev, cur = dummy, head
        while cur and cur.next:
            prev.next = cur.next
            cur.next = cur.next.next
            prev.next.next = cur
            prev, cur = cur, cur.next
        return dummy.next


sol = Solution()
ll = ListNode(1)
ll.next = ListNode(2)
ll.next.next = ListNode(3)
print(sol.swapPairs(ll))
