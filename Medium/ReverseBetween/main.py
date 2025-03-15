# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        lnode = head
        nums = []
        for i in range(left - 1):
            lnode = lnode.next
        st = lnode
        for i in range(right - left + 1):
            nums.append(lnode.val)
            lnode = lnode.next
        for i in range(right - left + 1):
            st.val = nums[len(nums) - i - 1]
            st = st.next
        n = head
        while (n != None):
            print(n.val)
            n = n.next


s = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, None)))))
s.reverseBetween(head, 2, 4)
