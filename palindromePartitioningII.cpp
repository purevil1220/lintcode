ass Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int n=s.length();
        if(n<=1) return 0;
        
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        
        for(int end=1; end<n; end++) {
            if(isPalindrome(s, 0, end)) {
                d[end]=0;
                continue;
            }
            
            for(int start=1; start<=end; start++) {
                if(isPalindrome(s, start, end))
                    d[end] = min(d[end], d[start-1]+1);
            }
        }
        
        return d[n-1];
    }
    

private:
    bool isPalindrome(string &s, int start, int end) {
        string::iterator is = s.begin()+start;
        string::iterator ie = s.begin()+end;
        int n=end-start+1;
        for(int i=0; i<n/2; i++) {
            if(*is!=*ie) return false;
            is++;
            ie--;
        }
        return true;
    }
};


