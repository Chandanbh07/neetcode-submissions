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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        while(n > 0){
            first = first->next;
            n--;
            if(first == NULL) return head->next;
        }
        
        ListNode* prev=NULL;
        ListNode* nxt=head->next;
        while(first){
            first = first->next;
            prev = second;
            second = nxt;
            nxt = second->next;
        }

        if(prev) prev -> next = nxt;

        return head;
        
    }
};
