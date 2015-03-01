etZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        
        // check first row && first col
        bool row1 = false;
        bool col1 = false;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for (int r=0; r<n; r++) {
            if(matrix[r][0]==0) {
                col1=true;
                break;
            }
        }
        
        for (int c=0; c<m; c++) {
            if(matrix[0][c]==0) {
                row1=true;
                break;
            }
        }
        
        for(int r=1; r<n; r++) for(int c=1; c<m; c++) {
            if(matrix[r][c]==0) {
                matrix[r][0]=0;
                matrix[0][c]=0;
            }
        }
        
        for(int r=1; r<n; r++) for(int c=1; c<m; c++) {
            if(matrix[r][0]==0||matrix[0][c]==0) matrix[r][c]=0;
        }
        
        if(row1) {
            for (int c=0; c<m; c++) matrix[0][c]=0;
        }
        
        if(col1) {
            for (int r=0; r<n; r++) matrix[r][0]=0;
        }
        
    }
};


