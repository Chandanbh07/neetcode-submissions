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
    // Reverse nodes in the range [groupStart, nextGroup)
    ListNode* reverse(ListNode* groupStart, ListNode* nextGroup) {
        ListNode* prev = nextGroup;

        while (groupStart != nextGroup) {
            ListNode* nextNode = groupStart->next;

            groupStart->next = prev;
            prev = groupStart;
            groupStart = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr || k == 1)
            return head;

        ListNode dummy(-1);
        ListNode* prevGroupTail = &dummy;

        ListNode* groupStart = head;

        while (groupStart) {

            // Find the next group's starting point
            ListNode* nextGroup = groupStart;
            int count = 0;

            while (count < k && nextGroup) {
                nextGroup = nextGroup->next;
                count++;
            }

            // Less than k nodes left
            if (count < k) {
                prevGroupTail->next = groupStart;
                break;
            }

            // Reverse current group
            prevGroupTail->next = reverse(groupStart, nextGroup);

            // groupStart becomes the tail after reversal
            prevGroupTail = groupStart;

            // Move to next group
            groupStart = nextGroup;
        }

        return dummy.next;
    }
};