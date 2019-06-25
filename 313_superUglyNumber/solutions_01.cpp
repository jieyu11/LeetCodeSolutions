class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // n = 12;
        // primes = {2, 7, 13, 19};
        
        int np=primes.size();
        if(np==0) return 0;
        // each next result is based on previous results!
        //
        // for each prime number, keep track on their 
        // current index under result vector.
        // all should start from 0, result[0] = 1;
        vector<int> pos(np, 0);
        vector<int> result(n,1);
        for(int i=1; i<n; i++){
            // next result should be the smallest after the current one.
            int next = INT_MAX;
            int idx = -1;
            for(int j=0; j<np; j++){
                int test = result[ pos[j] ] * primes[j];
                if(next > test ){
                    next = test;
                    idx = j;
                }
            }
            pos[idx]++;
            
            // check if other prime can also reach the same next value
            for(int j=0; j<np; j++){
                if(j!=idx && result[ pos[j] ] * primes[j] == next) pos[j]++;
            }
            
            result[i] = next;
        }
        return result[n-1];
    }
};
