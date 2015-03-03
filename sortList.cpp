ass Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(!head || !head->next) return head;
        
        ListNode *s=head;
        ListNode *f=head;
        
        while(f->next && f->next->next) {
            s=s->next;
            f=f->next->next;
        }
        
        f=s->next;
        s->next=NULL;
        
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(f);
        return merge(l1, l2);
        
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *d=&dummy;
        
        while(l1||l2) {
            if(l1 && l2) {
                if(l1->val<l2->val) {
                    d->next=l1;
                    l1=l1->next;
                } else {
                    d->next=l2;
                    l2=l2->next;
                }
                d=d->next;
            } else {
                if(l1) d->next=l1;
                if(l2) d->next=l2;
                break;
            }
        }
        
        return dummy.next;
    }
    
};


