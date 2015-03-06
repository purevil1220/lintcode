ass Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int mask=0;
        
        for (int ind=0; ind<31-j; ind++) mask=(mask<<1)+1;
        mask=mask<<(j-i+1);
        for (int ind=0; ind<i; ind++) mask=(mask<<1)+1;
        
        return (n&mask)+(m<<i);
        
    }
};
