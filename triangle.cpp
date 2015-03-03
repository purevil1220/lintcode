//dp
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if(triangle.empty()) return 0;
        
        int n=triangle.size();
        vector<int> d(n, INT_MAX);
        d[0]=triangle[0][0];
        
        for(int level=1; level<n; level++) {
            d[level]=d[level-1]+triangle[level][level]; 
            for (int r=level-1; r>0; r--) 
                d[r] = triangle[level][r]+min(d[r], d[r-1]);
            d[0]+=triangle[level][0];
        }
        
        int ret=INT_MAX;
        for(int i=0; i<n; i++) ret=min(ret, d[i]);
        return ret;
    }

};
// recursive, exponential time

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if(triangle.empty()) return 0;
        
        int sol=INT_MAX;
        vector<int> sofar;
        helper(triangle, sofar, 0, sol);
        
        return sol;
    }
    
    void helper(vector<vector<int>> &triangle, vector<int> &sofar, int lasti, int &sol) {
        int len = sofar.size();
        if(len==triangle.size()) {
            sol = min(sol, accumulate(sofar.begin(), sofar.end(), 0));
            return;
        }
        
        sofar.push_back(triangle[len][lasti]);
        helper(triangle, sofar, lasti, sol);
        sofar.pop_back();
        
        if(lasti<len) {
            sofar.push_back(triangle[len][lasti+1]);
            helper(triangle, sofar, lasti+1, sol);
            sofar.pop_back();
        }
        
        
    }
};


