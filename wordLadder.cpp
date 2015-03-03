ass Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here

        int len = start.length();
        queue<string> myq;
        
        myq.push(start);
        int middle=0;
        
        while(!myq.empty()) {
            queue<string> q2;
            while(!myq.empty()) {
                string cur = myq.front();
                myq.pop();
                
                for(int i=0; i<len; i++) {
                    char old =cur[i]; 
                    for (char c='a'; c<='z'; c++) {
                        if(c==old) continue;
                        cur[i]=c;
                        if(cur==end) return middle+2;
                        if(dict.find(cur)!=dict.end()) {
                            q2.push(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[i]=old;
                }
            }
            
            myq=q2;
            middle++;
        }
        
        return 0;
    }
    
};


