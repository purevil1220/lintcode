class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(!source||!target) return -1;
        if(target[0]=='\0') return 0;
        
        int is=0;
        while (source[is]!='\0') {
            if(source[is]==target[0]) {
                int it=0;
                while(source[is+it]!='\0' && target[it]!='\0' 
                    && source[is+it]==target[it]) 
                    it++;
                if(target[it]=='\0') return is;
            }
            is++;
        }
        
        return -1;
    }
};


