ass Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        
        if(A.empty()) return 0;
        
        int l=0; 
        int r=A.size()-1;
        while(l<r) {
            int m=l+(r-l)/2;
            if(A[m]==target) return m;
            if(A[m]>target) r=m;
            else l=m+1;
        }
        
        if(A[l]<target) return l+1;
        return l;
    }
};
