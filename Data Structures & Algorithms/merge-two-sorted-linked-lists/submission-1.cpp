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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        

        return merge(list1,list2);
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        else if(list1 == NULL){
             return list2;
            
        }else if(list2 == NULL){
             return list1;
            
        }

        if(list1->val <= list2->val){
            ListNode* newnext = merge(list1->next, list2 );
            list1->next = newnext;
             return list1;
            
        }else{
            ListNode* newnext = merge(list1,list2->next);
            list2->next = newnext;
             return list2;
            
        }
    }
};
