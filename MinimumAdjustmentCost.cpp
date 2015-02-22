class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int n=A.size();
        if(n<=1) return 0;
        
        vector<vector<int>> mat(n, vector<int>(100, 0));
        
        for(int row=0; row<n; row++) {
            for(int col=0; col<100; col++) {
                mat[row][col]=abs(A[row]-col-1);
            }
        }
        
        for(int row=1; row<n; row++) {
            for(int col=0; col<100; col++) {
                int l=max(0, col-target);
                int r=min(99, col+target);
                int tmp=INT_MAX;
                while(l<=r) {
                    tmp=min(tmp, mat[row][col]+mat[row-1][l]);
                    l++;
                }
                mat[row][col]=tmp;
            }
        }
        
        int ans=INT_MAX;
        for(int col=0; col<100; col++) ans=min(ans, mat[n-1][col]);
        
        return ans;
        
    }
};
