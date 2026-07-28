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

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* copy = dummy;

        int carry = 0;

        while (l1 && l2) {
            int sum = l1->val + l2->val;

            ListNode* newNode = new ListNode((sum + carry) % 10);

            carry = (sum + carry) / 10;

            copy->next = newNode;
            copy = copy->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            ListNode* newNode = new ListNode((l1->val+carry)%10);
            copy->next = newNode;
            copy = copy->next;

            carry = (l1->val+carry)/10;
            l1=l1->next;
        }

        while(l2){
            ListNode* newNode = new ListNode((l2->val+carry)%10);
            copy->next = newNode;
            copy = copy->next;

            carry = (l2->val+carry)/10;
            l2 = l2->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);
            copy->next = newNode;
        }
        return dummy->next;
    }
};
