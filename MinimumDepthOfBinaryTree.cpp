class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if(!root) return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        int cur=0;
        while(!q.empty()) {
            cur++;
            queue<TreeNode *> q1;
            while(!q.empty()) {
                TreeNode *tmp=q.front();
                q.pop();
                if(!tmp->left && !tmp->right) return cur;
                if(tmp->left) q1.push(tmp->left);
                if(tmp->right) q1.push(tmp->right);
            }
            q=q1;
        }
        
        return cur;
    }
};
