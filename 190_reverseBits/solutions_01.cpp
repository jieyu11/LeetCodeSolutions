class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i=0; i<16; i++){
            uint32_t a = n & 1 << i; // right
            uint32_t b = n & 1 << (31-i); // left
            b = b >> (31-2*i); // left move to right
            
            // if both a and b are 0 or 1 at bit i, 
            // doesn't need to swap
            if( (1 << i) & ~(a ^ b)) continue;
            
            a = a << (31-2*i); // right move to left
            n = n & ~(1 << (31-i));// mask
            n = n & ~(1 << i);// mask
            n |= a; // set
            n |= b; // set
        }
        return n;
    }
};
