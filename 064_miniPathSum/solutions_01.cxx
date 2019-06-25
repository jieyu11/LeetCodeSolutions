class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
            
        int nmax = max(n, m);
        vector<vector<int>> pathes(n, vector<int>(m, 0));
        // first row
        for(int i=0; i<m; i++){
            if(!i) pathes[0][i] = grid[0][i];
            else   pathes[0][i] = pathes[0][i-1] + grid[0][i];
        }
        // first column
        for(int i=1; i<n; i++){
            pathes[i][0] = pathes[i-1][0] + grid[i][0];
        }
        // next row by row
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                pathes[i][j] = min(pathes[i-1][j], pathes[i][j-1]) + grid[i][j];
            }
        }
        /*
        for(auto v : pathes){
            for(auto i : v) cout<<i<<" ";
            cout<<endl;
        }
        */
        return pathes[n-1][m-1];
    }
};

