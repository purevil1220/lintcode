class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.empty()) return nullptr;
        
        int n=lists.size();
        if(n==1) return lists[0];
        
        ListNode *ans=nullptr;
        for (int i=0; i<n; i++) ans=merge2lists(ans, lists[i]);
        
        return ans;
    }

private:
    ListNode *merge2lists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *dptr = &dummy;
        
        ListNode *d = dptr;
        while(l1&&l2) {
            if(l1->val<l2->val) {
                d->next = l1;
                l1=l1->next;
            } else {
                d->next=l2;
                l2=l2->next;
            }
            d=d->next;
        }
        
        if(l1) d->next=l1;
        if(l2) d->next=l2;
        return dptr->next;
    }
};
