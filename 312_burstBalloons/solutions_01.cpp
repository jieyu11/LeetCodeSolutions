class Solution {
public:

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        nums.insert( nums.begin(), 1);
        nums.insert( nums.end(), 1);
        vector<vector<int>> bursts(n+2, vector<int>(n+2, 0));
        for(int len=1; len <= n; len++){
            for( int istart = 1; istart <= n - len + 1; istart++){
                int iend = istart + len - 1;
                int max_burst = 0;
                for(int ifinal = istart; ifinal <= iend; ifinal++){
                    int currBur = bursts[istart][ifinal-1] + 
                        nums[istart-1] * nums[ifinal] * nums[iend+1] + 
                        bursts[ifinal+1][iend];
                    if(currBur > max_burst) max_burst = currBur;
                }
                bursts[istart][iend] = max_burst;
            }
        }
        return bursts[1][n];
    }
};
