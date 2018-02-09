# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 本题一般思路是使用两个指针，将其中一个指针(快指针)往前推进n步，然后两个指针同步推进，直到快指针到结尾
# 慢指针所指向的位置就是第n个节点，然后进行删除即可
# 下面的解法采用递归，返回从后往回数的索引和head，在索引等于n是返回head.next代替返回head即可
class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        def remove(head):
            if not head:
                return 0, head
            i, head.next = remove(head.next)
            return i+1, (head, head.next)[i+1==n]
        return remove(head)[1]
