ass Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> >  ans;
        vector<int> sol;
        
        int n=A.size();
        if(n<k) return ans;
        
        helper(A, k, 0, target, sol, ans);
        
        return ans;
    }
    
    void helper(vector<int> &A, int k, int cur, int target, vector<int>& sol, vector<vector<int>> &ans){
        if (target==0 && sol.size()==k) {
            ans.push_back(sol);
            return;
        }
        if(cur==A.size() || sol.size()==k) return;
        
        for (int i=cur; i<A.size(); i++) {
            sol.push_back(A[i]);
            helper(A, k, i+1, target-A[i], sol, ans);
            sol.pop_back();
        }
        
    }
};
