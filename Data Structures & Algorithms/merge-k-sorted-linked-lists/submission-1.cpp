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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; // minheap (Tells the pq that larger value has the lower priority)
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        priority_queue<ListNode* , vector<ListNode*> , Compare> minheap;

        for(auto head: lists){
            if(head)
                minheap.push(head);
        }

        ListNode dummy(0);
        ListNode* ans = &dummy;

        while(!minheap.empty()){
            ListNode* curr = minheap.top();
            minheap.pop();
            
            ans->next = curr;
            ans = ans->next;

            if(curr->next){
                minheap.push(curr->next);
            }
        }

        return dummy.next;
    }
};
