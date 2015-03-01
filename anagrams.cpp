ass Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string>> m;
        
        
        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }
        
        vector<string> ret;
        
        for (auto pair:m) {
            if(pair.second.size()>1) 
                ret.insert(ret.end(), pair.second.begin(), pair.second.end());
        }
        
        return ret;
    }
};
