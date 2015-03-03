ass Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        sort(A.begin(), A.end());
        
        int n=A.size();
        for (int i=0; i<n; i+=3) {
            if (i==n-1 || A[i]!=A[i+1]) return A[i];
        }
    }
};
