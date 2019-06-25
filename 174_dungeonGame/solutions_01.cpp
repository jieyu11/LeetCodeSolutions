class Solution {
public:
    void update(vector<vector<int>>& dungeon, int ncol, map<int, int> & needs, int need_previous, int jx, int ix){
        int n = ncol;
                int new_need = need_previous - dungeon[jx][ix];
                if (new_need <=0) new_need = 1; // if it needs <= 0, it still needs 1 to get here
                if( needs.find( jx*n+ix ) != needs.end() ){
                    if(new_need < needs[jx*n+ix]) needs[jx*n+ix] = new_need;
                }else{
                    needs.insert( make_pair(jx*n+ix, new_need) );
                }
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        /*
        dungeon = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}
        };
        */
        int m = dungeon.size();
        if (m==0) return 0;
        int n = dungeon[0].size();
        if (n==0) return 0;
        if (m==0 &&n==0){
            if(dungeon[0][0]>=0) return 1;
            else return (-1*dungeon[0][0] + 1);
        }
        // key: index, calculated as j * n + i, where i = 0 ... n, j = 0 ... m
        // value: how many power-ups needed at this position
        map<int, int> needs;
        int i = n - 1, j = m - 1;
        if( dungeon[j][i] >= 0 )
            needs.insert( make_pair(j*n+i, 1) );
        else 
            needs.insert( make_pair(j*n+i, -1*dungeon[j][i]+1) );
        
        queue<int> index;
        index.push(j*n+i); // start from right corner
        set<int> visited;
        visited.insert(j*n+i); // track the indexes, if visited, continue
        while(!index.empty()){
            int idx = index.front();
            index.pop();
            j = idx / n;
            i = idx % n;
            /*
            if(needs.find(idx)==needs.end())
                cout<<i<<" "<<j<<" not found "<<endl;
            else
                cout<<i<<" "<<j<<", "<<needs[idx]<<endl;
            */
            if(i-1>=0){
                update(dungeon, n, needs, needs[idx], j, i-1);
                if(visited.find(j*n+i-1) == visited.end()){
                    index.push( j*n+i-1);
                    visited.insert(j*n+i-1);
                }
            }
            if(j-1>=0){
                update(dungeon, n, needs, needs[idx], j-1, i);
                if(visited.find((j-1)*n+i) == visited.end()){
                    index.push( (j-1)*n+i);
                    visited.insert((j-1)*n+i);
                }
            }            
        }
        return needs[0];
    }
};
