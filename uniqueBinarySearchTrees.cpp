ass Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if(n<0) return 0;
        
        vector<int> vec(n+1, 0);
        vec[0]=1; 
        
        for(int i=1; i<=n; i++) {
            int l=0, r=i-1;
            int sum=0;
            while(l<r) sum+=2*vec[l++]*vec[r--];
            if(l==r) sum+=vec[l]*vec[r];
            vec[i]=sum;
        }
        
        return vec[n];
    }
};


