class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        if(s.length()<=1) return s;
        
        string::iterator ws=s.begin();
        string::iterator we=s.end()-1;
        reverseWord(ws, we);
        
        //reverse word by word

        while (true) {
            while(ws!=s.end() && *ws==' ') ws++;
            if (ws==s.end()) break;
            
            we=ws;
            while(we!=s.end() && *we!=' ') we++;
            
            we--;
            reverseWord(ws, we);
            ws=we+1;
        }
        
        // leading and trailing spaces
        ws=s.begin();
        while(ws!=s.end() && *ws==' ') ws++;
        if(ws==s.end()) return "";
        
        we=s.end()-1;
        while(we!=ws && *we==' ') we--;
        s= string(ws, we+1);
        
        // multiple spaces 
        ws=s.begin();
        while(true) {
            while(ws!=s.end()&&*ws!=' ') ws++;
            if(ws==s.end()) break;
            
            ws++;
            while(ws!=s.end()&&*ws==' ') s.erase(ws);
        }
        
        
        return s;
        
    }
    
private:
    void reverseWord(string::iterator it1, string::iterator it2) {
        while(it1!=it2) {
            swap(*it1, *it2);
            it1++;
            if(it1==it2) break;
            it2--;
        }
    }
};


