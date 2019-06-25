class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<=1) return;
        int level = n / 2;
        for(int i=0; i<level; i++){
            for(int j=i; j<n-i-1; j++){
                swap(matrix[i][j], matrix[n-j-1][i]);
                swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1], matrix[j][n-i-1]);
            }
        }
    }
};
