ass Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n=A.size();
        vector<vector<int>> d(k+1, vector<int>(target+1, 0));
        d[0][0]=1;
        
        for(int i=0; i<n; i++) {
            for(int row=k; row>=1; row--) {
                for (int col=target; col>=0; col--) {
                    if(col>=A[i]) d[row][col]+=d[row-1][col-A[i]];
                    if(row==k&&col==target) break;
                }
            }
        }
        
        return d[k][target];
        
    }
};
