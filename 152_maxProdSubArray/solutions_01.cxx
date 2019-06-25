class Solution {
public:
    int maxProductNoneZero(vector<int>& nums, int idx0, int idx1){
        // either nums[0] * nums[i] or nums[j] * nums[n-1]
        int prodmax = INT_MIN;
        int forward = 1;
        int backward = 1;
        for(int i=0; i<=idx1-idx0; i++){
            forward *= nums[idx0+i];
            backward *= nums[idx1-i];
            prodmax = max(prodmax, max(forward, backward));
        }  
        return prodmax;
    }
    int maxProduct(vector<int>& nums) {
        //nums = {-2,3,-4};
        int n = nums.size();
        if(n<=0) return 0;
        if(n==1) return nums[0];
        vector<int> v_izero;
        for(int i=0; i<n; i++){
            if(!nums[i]) v_izero.push_back(i);
        }
        if(v_izero.empty()) return maxProductNoneZero(nums, 0, n-1);
        
        int nzero = v_izero.size();
        int max_prod = 0;
        for(int i=0; i<nzero+1; i++){
            int prod = 0;
            if(i==0) prod = maxProductNoneZero(nums, 0, v_izero[i]-1);
            else if(i==nzero) prod = maxProductNoneZero(nums, v_izero[i-1]+1, n-1);
            else prod = maxProductNoneZero(nums, v_izero[i-1]+1, v_izero[i]-1);
            if(prod > max_prod) max_prod = prod;
        }
        return max_prod;
    }
};
