/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// using i64 = long long;
// i64 createNum(ListNode* head) {
//     i64 s = 0;
//     i64 i = 1;
//     i64 it = 1;
//     while (head) {
//         s += head->val * i;
//         i *= 10;
//         head=head->next;
//         it++;
//     }
//     return s;
// }

class Solution {
   public:
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     i64 n1 = createNum(l1);
    //     i64 n2 = createNum(l2);
    //     i64 s  = n1 + n2;

    //     int curr = s % 10;
    //     s = s/10;
    //     ListNode* prev = new ListNode(curr);
    //     ListNode* head = prev;
    //     while (s != 0) {
    //         i64 curr = s % 10;
    //         prev->next = new ListNode(curr);
    //         prev=prev->next;
    //         s = s/10;
    //     }
    //     return head;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        return dummy.next;
    }
};
