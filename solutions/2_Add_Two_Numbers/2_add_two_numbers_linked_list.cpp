/**
 * author: yfzhang
 * date: 2017-03-07
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* pres = res;
        int carry = 0;
        for (ListNode* p1 = l1, *p2 = l2; p1 != NULL || p2 != NULL; p1 = (p1 == NULL ? NULL : p1->next), p2 = (p2 == NULL ? NULL : p2->next), pres = pres->next)
        {
            int a1 = p1 == NULL? 0:p1->val;
            int a2 = p2 == NULL? 0:p2->val;
            int val = a1 + a2 + carry;
            carry = val / 10;
            val = val % 10;
            pres->next = new ListNode(val);
        }
        if (carry > 0)
        {
            pres->next = new ListNode(carry);
        }
        return res->next;
    }
};
