truct listNode_cmp{
    bool operator()(ListNode *lhs, ListNode *rhs){
        return lhs->val > rhs->val;
    }
};



class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.empty()) return nullptr;
        
        // if(k==1) return lists[0];
        
        priority_queue<ListNode *, vector<ListNode *>, listNode_cmp> minHeap;
        for(auto it:lists) {
            if(it) minHeap.push(it);
        }
        
        ListNode dummy(0);
        ListNode *cur=&dummy;
        while(!minHeap.empty()) {
            cur->next=minHeap.top();
            cur=cur->next;
            
            minHeap.pop();
            if(cur->next) minHeap.push(cur->next);
        }
        
        return dummy.next;
    }

};
