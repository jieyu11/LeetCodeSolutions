class Solution {
public:
    bool searchSub(vector<vector<int>>& matrix, int i0, int j0, int i1, int j1, int target){
        if(i0==i1 && j0==j1){ 
            if(target == matrix[i0][j0]) return true; else return false;
        }
        int imid = (i0 + i1) / 2;
        int jmid = (j0 + j1) / 2;
        if (target == matrix[imid][jmid]) return true;
        if (target <  matrix[imid][jmid]){
            bool s1 = false, s2 = false;
            if(imid > i0) s1 = searchSub(matrix, i0, j0, imid-1, j1, target);
            if(jmid > j0) s2 = searchSub(matrix, imid, j0, i1, jmid-1, target);
            return  s1 || s2;
        }
        if (target >  matrix[imid][jmid]){
            bool s1 = false, s2 = false;
            if(jmid < j1) s1 = searchSub(matrix, i0, jmid+1, i1, j1, target);
            if(imid < i1) s2 = searchSub(matrix, imid+1, j0, i1, jmid, target);
            return s1 || s2;
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        a b c
        d e f
        g h i
        
        facts:
        e > a, d, b
        e < h, f, i
        e, c, g relationshi is not known
        */
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;
        if(target < matrix[0][0] || target > matrix[n-1][m-1]) return false;
        
        return searchSub(matrix, 0, 0, n-1, m-1, target);
    }
};
