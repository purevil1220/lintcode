ass Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        // write your code here
        int n=A.size();
        if(n<=2) return A;
        
        int nneg = partition(A);
        
        int l,r;
        if(nneg>n/2) {
            l=1; r=n-1;
        } else if (n-nneg>n/2) {
            l=0; r=n-2;
        } else {
            l=0; r=n-1;
        }
        
        while(l<r) {
            swap(A[l], A[r]);
            l+=2; r-=2;
        }
        
        return A;
        
        
    }
    
    int partition(vector<int> &A) {
        int l=0;
        int r=A.size()-1;
        
        while (l<=r) {
            if(A[l]<0) l++;
            else if(A[l]>0) swap(A[l], A[r--]);
            else throw runtime_error("has 0 inside, wrong input!");
        }
        
        return l;
        
    }
};


