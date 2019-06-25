class Solution {
public:
    int integerBreak(int n) {
        vector<int> ref{0,0,1,2};
        for(int i=4; i<=n; i++){
            int j = 2; 
            int pmax = 0;
            while(j<=i-2){
                int test = j * max(ref[i-j], i-j);
                if(pmax < test) pmax = test;
                j++;
            }
            ref.push_back(pmax);
        }
        return ref[n];
    }
};
