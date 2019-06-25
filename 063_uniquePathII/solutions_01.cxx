class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*
        obstacleGrid =
        {
            {0,0,0,0,1,0},
            {0,0,0,0,0,0},
            {0,1,0,0,1,0},
            {0,0,0,0,0,0}
        }; */
        
        int n = obstacleGrid.size();
        if(!n) return 0;
        int m = obstacleGrid[0].size(); 
        
        // corner cases:
        if(obstacleGrid[0][0]) return 0;
        if(n==1&&m==1) return 1;
        
        int nmax = max(n, m);
        vector<vector<int>> pathes(n, vector<int>(m, 0));
        int i = 0;
        while(i<nmax){
            for(int j=min(i,n); j<m; j++){
                if(i>=n) break;
                if(i==0){ // first row
                    if(!j) continue;
                    if(obstacleGrid[i][j]) break;
                    pathes[i][j] = 1;
                }else{ // rest of rows
                    if(obstacleGrid[i][j]) continue;
                    pathes[i][j] = pathes[i-1][j] + pathes[i][j-1];
                }
            }
            for(int j=min(i,m); j<n; j++){
                if(i>=m) break;
                if(i==0){ // first column
                    if(!j) continue;
                    if(obstacleGrid[j][i]) break;
                    pathes[j][i] = 1;
                }else{ // rest of columns
                    if(obstacleGrid[j][i]) continue;
                    pathes[j][i] = pathes[j-1][i] + pathes[j][i-1];
                }
            }
            i++;
        }
        
        /*
        for(auto v : pathes){
            for(auto i : v) cout<<i<<" ";
            cout<<endl;
        }*/
        
        return pathes[n-1][m-1];
    }
};
