class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next=head;
        head=d;
        
        for(int i=1; i<m; i++) head=head->next;
        ListNode *tail=head->next;
        
        for(int i=0; i<n-m; i++) tail=tail->next;
        
        ListNode *l1=head->next;
        ListNode *l2=tail->next;
        
        tail->next=nullptr;
        head->next = reverseList(l1);
        l1->next=l2;
        
        return d->next;
    }
private: 
    ListNode *reverseList(ListNode *head) {
        // write your code here
        if(head==nullptr) return head;
        ListNode d(0);
        ListNode *dummy=&d;
        dummy->next = head;

        while(head->next) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }

        return dummy->next;
    }

};
