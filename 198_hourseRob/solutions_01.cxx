class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> max_inc(n, 0); max_inc[0] = nums[0]; // maximum include the current number
        vector<int> max_exc(n, 0);
        for(int i=1; i<n; i++){
            // current number excluded, sum either including or not included the previous one
            max_exc[i] = max(max_exc[i-1], max_inc[i-1]);
            max_inc[i] = max_exc[i-1] + nums[i];
        }
        return max(max_exc[n-1], max_inc[n-1]);
    }
};
