ass Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(!root) return 0;
        
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};


