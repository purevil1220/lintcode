ass Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> ans;
        vector<string> sol;
        
        if(s.length()==0) return ans;
        
        helper(s, 0, sol, ans);
        return ans;
    }
    
private:
    void helper(string s, int start, vector<string> &sol, vector<vector<string>> &ans) {
        if(start==s.length()) {
            ans.push_back(sol);
            return;
        }
        
        for(int end=start; end<s.length(); end++) {
            string cur = s.substr(start, end-start+1);
            if(isPalindrome(cur)) {
                sol.push_back(cur);
                helper(s, end+1, sol, ans);
                sol.pop_back();
            }
        }
    }
    
    bool isPalindrome(string str) {
        int n=str.length();
        for(int i=0; i<n/2; i++) {
            if(str[i]!=str[n-1-i]) return false;
        }
        return true;
    }
};


