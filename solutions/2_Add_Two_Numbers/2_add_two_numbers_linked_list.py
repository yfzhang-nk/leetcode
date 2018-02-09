# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        carry = 0
        ret_l = ListNode(0)
        tmp_l = ret_l
        while l1 and l2:
            val = l1.val + l2.val + carry
            tmp_l.next = ListNode(val%10)
            carry = int(val/10)
            tmp_l = tmp_l.next
            l1 = l1.next
            l2 = l2.next
        if l1:
            tmp_l.next = l1
        elif l2:
            tmp_l.next = l2
        while tmp_l.next:
            val = tmp_l.next.val + carry
            tmp_l.next.val = val % 10
            carry = int(val/10)
            tmp_l = tmp_l.next
        if carry > 0:
            tmp_l.next = ListNode(carry)
        return ret_l.next
        
