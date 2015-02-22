class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        if(!head||!head->next) return;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next=head;
        
        ListNode* s = d;
        ListNode* f = d;
        while(f) {
            f=f->next;
            if(f) {
                f=f->next;
                s=s->next;
            } else break;
        }
        
        f=reverseList(s->next);
        s->next=nullptr;
        s=d->next;
        
        mergeList(s, f);
        
        head=d->next;
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
    
    void mergeList(ListNode* l1, ListNode* l2) {
        while(l2) {
            ListNode* tmp=l1->next;
            l1->next=l2;
            l2=l2->next;
            l1->next->next=tmp;
            l1=tmp;
        }
    }
};
