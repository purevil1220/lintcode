class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.size()==0) return 0;
        int n = A.size();
        vector<bool> dp(m+1, false);
        dp[0] = true;
        for (int i=0; i<n; i++) 
            for (int j=m; j>0; j--) {
                if (A[i]<=j && dp[j-A[i]]==true) dp[j] = true;
            }
        for (int j=m; j>=0; j--)
            if (dp[j]==true) return j;
        
    }
};
