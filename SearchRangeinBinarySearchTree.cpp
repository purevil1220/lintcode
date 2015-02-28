ass Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> sol;
        helper(root, k1, k2, sol);
        return sol;
        
    }
    
private:
    void helper(TreeNode* root, int k1, int k2, vector<int> &sol) {
        if(!root) return;
        helper(root->left, k1, k2, sol);
        if(root->val>=k1 &&root->val<=k2) sol.push_back(root->val);
        helper(root->right, k1, k2, sol);
    }
};


