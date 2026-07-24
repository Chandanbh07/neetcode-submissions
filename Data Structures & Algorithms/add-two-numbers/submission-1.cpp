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
        int carry=0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != NULL && temp2 != NULL){
             int sum = temp1->val + temp2 -> val + carry;
             ListNode* newnode = new ListNode(sum%10);
             curr->next = newnode;
             carry = sum/10;
             temp1 = temp1->next;
             temp2 = temp2->next;
             curr = curr->next;
        }

        while(temp1 != NULL){
            int sum = temp1->val +carry;
             ListNode* newnode = new ListNode(sum%10);
             curr->next = newnode;
             carry = sum/10;
             temp1 = temp1->next;
             curr = curr->next;
        }

        while(temp2 != NULL){
            int sum = temp2->val+carry;
             carry = sum/10;
             ListNode* newnode = new ListNode(sum%10);
             curr->next = newnode;
             temp2 = temp2->next;
             curr = curr->next;
        }
        
        if(carry>0) curr->next = new ListNode(carry);

        return dummy->next;
    }
};
