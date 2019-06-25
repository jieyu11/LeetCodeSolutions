class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        multiset<int, std::greater<int>> candidates;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int lower = (i+1) * (j+1) - 1;
                if(lower > k) continue;
                candidates.insert(matrix[i][j]);
                if(candidates.size()>k)  candidates.erase( candidates.begin() );
            }
        }
        
        return *candidates.begin();
    }
};
