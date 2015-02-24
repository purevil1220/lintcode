ass Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        if(grid.empty()) return 0;
        
        int n=grid.size();
        int m=grid[0].size();
        for(int row=0; row<n; row++) {
            for (int col=0; col<m; col++) {
                if(row==0&&col==0) continue;
                else if(row==0) grid[row][col]+=grid[row][col-1];
                else if(col==0) grid[row][col]+=grid[row-1][col];
                else grid[row][col]+=min(grid[row][col-1], grid[row-1][col]);
            }
        }
        return grid[n-1][m-1];
    }
};


