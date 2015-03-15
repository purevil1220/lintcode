tion of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head || !head->next) return head;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        ListNode *p = head;
        
        while(p) {
            if(p->next && p->val==p->next->val) {
                int cur=p->val;
                while (p&&p->val==cur) p=p->next;
            } else {
                d->next = p;
                d=d->next;
                p=p->next;
            }
        }
        
        d->next = NULL;
        
        return dummy.next;
    }
};


