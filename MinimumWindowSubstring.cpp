ass Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        unordered_map<char, int> targetMap;
        unordered_map<char, int> sourceMap;
        
        int n=target.length();
        if(n==0) return "";
        
        for(auto it=target.begin(); it!=target.end(); it++) {
            if (targetMap.find(*it)==targetMap.end()) targetMap[*it]=1;
            else targetMap[*it]++;
            // this line is cruecial, must initialize sourceMap
            sourceMap[*it]=0;
        }
        
        string ans;
        int minLen = INT_MAX;
        int ct=0;
        
        int start=0;
        for (int end=0; end< source.length(); end++) {
            
            if (sourceMap.find(source[end])!=sourceMap.end()) {
                sourceMap[source[end]]++;
                if(sourceMap[source[end]]<=targetMap[source[end]]) ct++;
            } 
            
            //move ileft 
            if(ct==n) {
                while(sourceMap.find(source[start])==sourceMap.end()
                    ||sourceMap[source[start]]>targetMap[source[start]]) {
                    if(sourceMap.find(source[start])!=sourceMap.end()) {
                        sourceMap[source[start]]--;
                    }
                    start++;
                }
                
                if(end-start+1<minLen) {
                    minLen=(end-start)+1;
                    ans = source.substr(start, minLen);
                }
                
                start++;
                ct--;
            }
        }
        
        return ans;
    }
};
