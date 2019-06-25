class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=0) return 0;
        if(n<=3) return 1;
        int count = 1;
        int j = 2;
        while(j*j <= n){
            // count the number of divisors excluding itself and 1
            // if find an even number of divisors, switch it off.
            // if it is an odd number, switch it on. 
            // --> only when the sqare root is itself, otherwise, divisors come with pairs.
            // the problem convert to how many numbers y <= n having y = x * x
            
            count++;
            j++;
        }
        return count;
    }
};
