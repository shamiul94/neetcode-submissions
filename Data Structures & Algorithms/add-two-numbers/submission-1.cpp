class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // stack object
        ListNode* current = &dummy; // pointer that moves

        int carry = 0;

        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            int sum = a + b + carry;

            current->next = new ListNode(sum % 10);
            current = current->next;

            carry = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};