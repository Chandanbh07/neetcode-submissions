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
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* prev=NULL;

        while(head != tail){
            ListNode* nxt= head->next;

            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* last = head;
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(last){
            int window = 0;
            ListNode* first = last;
            while(window < k && last){
                last = last->next;
                window++;
            }
            if(window == k){
                tail->next = reverse(first,last);
                tail = first;
            }else{
                tail->next = first;
            }
        }

        return dummy.next;
    }
};
