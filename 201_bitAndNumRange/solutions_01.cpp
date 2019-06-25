class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //m = 5;
        //n = 7;
        // for AND to return 1 at a bit, all numbers from m to n 
        // should have 1 at this bit
        // 5 == 0101
        // 6 == 0110
        // 7 == 0111
        // result = 4 = 0100
        // in order to have 4, the range from m to n cannot be larger than 4
        // besides, it should be 4 -- 7 inclusive.
        // 
        // check bit by bit!
        if(m==n || m==0) return m;
        int nums = n - m + 1;
        int ib=0; 
        int result = 0;
        while(ib<32){
            // starting from the second bit, first bit already considered above.
            ib++;
            // the bit number, if it is set 1, i.e.
            // 01 == 1 (first bit)
            // 10 == 2 (second bit)
            int nb = pow(2,ib);
            
            if (nb > n) break;
            
            if(nums > nb) continue;
            // for the 3rd bit ib=2 to set, 
            // number m -- n should be in range of same period, m=5, n=7, then m/4 == 1 == n/4
            // and it should be not 0th or 2nd or 4th ... period, otherwise the bit is 0!
            if((m / nb)%2==0 || (n / nb)%2==0) continue;
            
            // if all OK. then this bit should be set to 1.
            result |= 1 << ib;
        }
        return result;
    }
};
