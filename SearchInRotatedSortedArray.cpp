ass Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int n=A.size();
        if(n==0) return -1;
        
        int low = searchLow(A);
        
        int l;
        int r;
        if(A[0]<=target) {
            l=0;
            r=(low-1+n)%n;
        } else if(A[n-1]>=target) {
            l=low;
            r=n-1;
        } else return -1;
        
        // binary search
        while(l<=r) {
            int m=l+(r-l)/2;
            if(A[m]==target) return m;
            else if(A[m]<target) l=m+1;
            else r=m-1;
        }
        
        return -1;
    }

private:
    int searchLow(vector<int> &A) {
        int l=0; 
        int r=A.size()-1;
        
        while(l<r) {
            if(A[r]>A[l]) return l;
            
            int m=l+(r-l)/2;
            if(A[m]>A[l]) l=m+1;
            else r=m;
        }
        
        
        return l;
    }
};


