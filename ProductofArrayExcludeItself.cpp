ass Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        vector<long long> e;
        if (n<=1) return e;
        
        vector<long long> ans(n, 1);
        
        long long cur = 1;
        for (int start=n-1; start>0; start--) {
            cur*=nums[start];
            ans[start] = cur;
        }
        
        cur=1;
        for (int i=0; i<n-1; i++) {
            ans[i]=cur*ans[i+1];
            cur*=nums[i];
        }
        ans[n-1] = cur;
        
        return ans;
    }
};


