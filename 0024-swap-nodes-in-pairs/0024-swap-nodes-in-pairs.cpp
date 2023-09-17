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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            // If the list is empty or has only one element, no need to swap.
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;

        // Swap the nodes.
        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};
