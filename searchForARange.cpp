ass Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ans = {-1, -1};
        int n=A.size();
        if (n==0) return ans;
        
        int l=0;
        int r=n-1;
        while(l<r) {
            int m=l+(r-l)/2;
            if(A[m]<target) l=m+1;
            else r=m;
        }
        
        if(A[l]==target) ans[0]=l;
        else return ans;
        
        r=n-1;
        while(l<r) {
            int m=l+(r-l)/2;
            if(A[m]>target) r=m-1;
            else {
                if(m!=l) l=m;
                else {
                    if(A[r]==target) l=r;
                    break;
                }
            }
        }
        ans[1]=l;
        
        return ans;
    }
};
