class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        if(n==2) return abs(nums[0]-nums[1]);
        sort(nums.begin(), nums.end());
        long sum = 0;
        for(int i=1; i<n; i++){sum += abs(nums[i]-nums[0]);}
        for(int i=1; i<n; i++){
            long sum2 = sum - (n-2*i)*(nums[i]-nums[i-1]);
            if(sum2 < sum) sum = sum2;
        }
        return sum;
    }
};
