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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* tail = reverseList(second);

        ListNode* curr = head;

        while(curr && tail){
            ListNode* nxt1 = curr->next;
            ListNode* nxt2 = tail->next;

            curr->next = tail;
            tail->next = nxt1;

            curr = nxt1;
            tail = nxt2;
        }
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr->next;

            curr -> next = prev;
            
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
