ass Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dummy(0);
        ListNode *d=&dummy;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL||carry>0) {
            int sum=carry;
            if(l1) { sum+=l1->val; l1=l1->next;}
            if(l2) { sum+=l2->val; l2=l2->next;}
            
            ListNode *cur=new ListNode(sum%10);
            d->next=cur;
            d=d->next;
            carry=sum/10;
        }
        
        if(dummy.next==NULL) dummy.next=new ListNode(0);
        
        return dummy.next;
    }
};


