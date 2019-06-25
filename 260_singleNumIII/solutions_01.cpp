class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if(n<=1) return result;
        
         // and not from the two single numbers
        int andnot = nums[0];
        for(int i=1; i<n; i++){
            andnot ^= nums[i];
        }
        
        // find the first 1 from right
        int idig = 0;
        while(true){
            if(andnot & 1 << idig) break;
            idig++;
        }
        
        // find the first number to have idig set
        int istart = 0;
        while(true){
            if(nums[istart] & 1 << idig) break;
            istart++;
        }
        int andnot_one = nums[istart];
        for(int i=istart+1; i<n; i++){
            if(nums[i] & 1 << idig) andnot_one ^= nums[i];
        }
        result.push_back(andnot_one);
        
        // a ^ b = c
        // a = b ^ c
        result.push_back( (andnot_one ^ andnot) );
        return result;
    }
};
