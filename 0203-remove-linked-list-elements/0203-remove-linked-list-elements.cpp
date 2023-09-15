class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next) {
            if (prev->next->val == val) {
                ListNode* temp = prev->next;
                prev->next = temp->next;
                delete temp;
            } else {
                prev = prev->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};
