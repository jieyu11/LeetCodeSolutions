class Solution {
public:
    int countPrimes(int n) {
        //n = 999983;
        if(n<=2) return 0;
        if(n==3) return 1;
        if(n<=5) return 2;

        vector<bool> excluded(n, false);
        int test = 1;
        int count = 0;
        while( test < n-2){
            if(test<=2) test++;
            else        test+=2;
            if(excluded[test]) continue;
            int m = 2;
            while( m*test < n){
                excluded[ m * test] = true;
                m++;
            }
            count++;
        }
        return count;
    }
};
