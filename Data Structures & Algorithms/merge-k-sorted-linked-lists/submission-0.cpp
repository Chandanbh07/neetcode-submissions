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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
       int k = lists.size();

       while(k > 1){
        int i=0, j=k-1;

        while(i<j){
            lists[i] = merge(lists[i],lists[j]);
            i++;
            j--;
        }
        k = (k+1)/2;
       }
       return lists[0];
    }

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        
        tail->next = a ? a:b;

        return dummy.next;
    }
};
