class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n<3) return 0;
        
        int gap = A[1] - A[0], gap_count = 1, total = 0, current =0;
        for(int i=2; i<n; i++){
            int tmp = A[i] - A[i-1];
            if(tmp == gap) gap_count++;
            else{
                gap_count = 1; 
                if(current){
                    total += current;
                    current = 0;
                }
                gap = tmp;
                continue;
            }
            if(gap_count>=2) current += gap_count - 1;
        }
        total += current;
        return total;
    }
};
