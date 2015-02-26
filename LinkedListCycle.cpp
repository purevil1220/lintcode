ass Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if(!head || !head->next) return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (slow!=fast) {
            if(!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return true;
    }
};
