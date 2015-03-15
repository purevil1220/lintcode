class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int n=A.size();
        int m=B.size();
        
        if((n+m)%2==1) return findkth(A, 0, B, 0, (m+n+1)/2);
        else return 1.0*(findkth(A, 0, B, 0, (m+n)/2+1)+findkth(A, 0, B, 0, (m+n)/2))/2;
    }
    
private:
    int findkth(vector<int> &A, int a, vector<int> &B, int b, int k) {
        int n=A.size();
        int m=B.size();
        
        if(a>=n) return B[b+k-1];
        if(b>=m) return A[a+k-1];
        
        if(k<=1) return min(A[a], B[b]);
        
        int pa=min(n, a+k/2)-1;
        int pb=min(m, b+k/2)-1;
        
        if(A[pa]>B[pb]) return findkth(A, a, B, pb+1, k-(pb-b)-1);
        if(A[pa]<B[pb]) return findkth(A, pa+1, B, b, k-(pa-a)-1);
        return A[pa];
    }
};


