class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        if(n==0) return;
        int m = matrix[0].size();
        if(m==0) return;
        sums = vector<vector<int>> (n+1, vector<int>(m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1]);
    }
    private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
