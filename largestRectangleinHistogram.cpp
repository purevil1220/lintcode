class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        stack<int> s;
        height.insert(height.begin(), 0);
        height.insert(height.end(), 0);
        
        int n=height.size();
        int sol=0;
        
        for (int i=0; i<n; i++) {
            while(!s.empty() && height[i]<height[s.top()]) {
                int cur=s.top();
                s.pop();
                int l = s.top();
                sol=max(sol, height[cur]*(i-l-1));
            }
            s.push(i);
        }
        
        return sol;
    }
};



