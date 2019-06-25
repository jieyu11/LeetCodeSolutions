class Solution {
public:
    // i,j hasn't been visited
    void connected(vector<vector<char>>& grid, vector<vector<bool>>& visited, const int & n, const int & m, int i0, int j0){
        stack<pair<int,int>> totest;
        totest.push({i0,j0});
        while(!totest.empty()){
            pair<int,int> ij = totest.top();
            totest.pop();
            int i = ij.first, j = ij.second;
            visited[i][j] = true;
            if(i-1>=0 && !visited[i-1][j] && grid[i-1][j] == '1') totest.push({i-1,j});
            if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] == '1') totest.push({i,j-1});
            if(i+1 <n && !visited[i+1][j] && grid[i+1][j] == '1') totest.push({i+1,j});
            if(j+1>=0 && !visited[i][j+1] && grid[i][j+1] == '1') totest.push({i,j+1});
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        
        int nisland = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    nisland++;
                    connected(grid, visited, n, m, i, j);
                }
            }
        }

        return nisland;
    }
};
