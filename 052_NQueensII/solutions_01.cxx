class Solution {
public:
    void check(const int & n, int row, vector<vector<bool>> cell, vector<bool> column, int & count){
        vector<int> idx;
        for(int i=0; i<n; i++){
            if(column[i]) continue;
            if(cell[row][i]) continue;
            idx.push_back(i);
        }
        if(idx.empty()) return;
        if(row==n-1){count++; return;}
        
        for(int i : idx){
            vector<bool> next_column = column;
            next_column[i] = true;
            vector<vector<bool>> next_cell = cell;
            for(int j=0; j<i; j++){
                if(row+i-j>=n) continue;
                next_cell[row+i-j][j] = true;
            }
            for(int j=i+1; j<n; j++){
                if(row-i+j>=n) continue;
                next_cell[row+j-i][j] = true;
            }
           check(n, row+1, next_cell, next_column, count);
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        check(n, 0, vector<vector<bool>>(n, vector<bool>(n, false)), vector<bool>(n, false), count);
        return count; 
    }
};
